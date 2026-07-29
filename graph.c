#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "../logger/logger.h"
#include "../memory/memory.h"

Graph *createGraph(void)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    if(graph == NULL)
    {
        logError("Graph allocation failed");
        return NULL;
    }

    incrementAllocations();

    graph->vertices = 0U;

    for(uint32_t i = 0U; i < MAX_STATIONS; i++)
    {
        graph->adjList[i] = NULL;
    }

    logInfo("Graph created");

    return graph;
}

int addStation(Graph *graph, const char *name)
{
    if(graph == NULL)
    {
        return -1;
    }

    if(graph->vertices >= MAX_STATIONS)
    {
        logError("Maximum station limit reached");
        return -1;
    }

    uint32_t id = graph->vertices;

    graph->stations[id].stationId = id;

    strncpy(graph->stations[id].stationName, name, NAME_LEN - 1U);
    graph->stations[id].stationName[NAME_LEN - 1U] = '\0';

    graph->stations[id].active = 1U;
    graph->vertices++;

    logInfo("Station added");

    return (int)id;
}

void addConnection(Graph *graph, int src, int dest)
{
    if(graph == NULL)
    {
        return;
    }

    Edge *newNode = (Edge *)malloc(sizeof(Edge));

    if(newNode == NULL)
    {
        logError("Edge allocation failed");
        return;
    }

    incrementAllocations();

    newNode->destination = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    Edge *reverseNode = (Edge *)malloc(sizeof(Edge));

    if(reverseNode == NULL)
    {
        logError("Reverse edge allocation failed");
        return;
    }

    incrementAllocations();

    reverseNode->destination = src;
    reverseNode->next = graph->adjList[dest];
    graph->adjList[dest] = reverseNode;

    logInfo("Connection added");
}

void removeStation(Graph *graph, int stationId)
{
    if(graph == NULL)
    {
        return;
    }

    if((stationId < 0) || (stationId >= (int)graph->vertices))
    {
        return;
    }

    graph->stations[stationId].active = 0U;

    printf("Station Removed Successfully\n");

    logInfo("Station Removed");
}

void removeConnection(Graph *graph, int src, int dest)
{
    Edge *curr;
    Edge *prev;

    curr = graph->adjList[src];
    prev = NULL;

    while(curr != NULL)
    {
        if(curr->destination == dest)
        {
            if(prev == NULL)
            {
                graph->adjList[src] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            free(curr);
            incrementFrees();
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    curr = graph->adjList[dest];
    prev = NULL;

    while(curr != NULL)
    {
        if(curr->destination == src)
        {
            if(prev == NULL)
            {
                graph->adjList[dest] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            free(curr);
            incrementFrees();
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Connection Removed Successfully\n");
}

int findStation(Graph *graph, const char *name)
{
    if(graph == NULL)
    {
        return -1;
    }

    for(uint32_t i = 0U; i < graph->vertices; i++)
    {
        if((graph->stations[i].active == 1U) &&
           (strcmp(graph->stations[i].stationName, name) == 0))
        {
            return (int)i;
        }
    }

    return -1;
}

void displayStations(Graph *graph)
{
    printf("\nStations:\n");

    for(uint32_t i = 0U; i < graph->vertices; i++)
    {
        if(graph->stations[i].active == 1U)
        {
            printf("%u. %s\n", graph->stations[i].stationId, graph->stations[i].stationName);
        }
    }
}

void displayGraph(Graph *graph)
{
    if(graph == NULL)
    {
        return;
    }

    printf("\n");
    printf("====================================\n");
    printf("NETWORK CONNECTIONS\n");
    printf("====================================\n\n");

    for(uint32_t i = 0U; i < graph->vertices; i++)
    {
        if(graph->stations[i].active == 0U)
        {
            continue;
        }
        printf("%s", graph->stations[i].stationName);

        Edge *temp = graph->adjList[i];

        while(temp != NULL)
        {
            printf(" -> %s", graph->stations[temp->destination].stationName);
            temp = temp->next;
        }

        printf("\n");
    }
}

void freeGraph(Graph *graph)
{
    if(graph == NULL)
    {
        return;
    }

    for(uint32_t i = 0U; i < graph->vertices; i++)
    {
        Edge *temp = graph->adjList[i];

        while(temp != NULL)
        {
            Edge *next = temp->next;
            free(temp);
            incrementFrees();
            temp = next;
        }
    }

    free(graph);
    incrementFrees();

    logInfo("Graph memory released");
}
