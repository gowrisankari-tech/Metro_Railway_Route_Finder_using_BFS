#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

#define MAX_STATIONS 200U
#define NAME_LEN 50U

typedef struct
{
    char lineCode;
    int stationId;
    char active;
} NormalStation;

#pragma pack(push, 1)

typedef struct
{
    char lineCode;
    int stationId;
    char active;
} PackedStation;

#pragma pack(pop)

typedef struct
{
    uint32_t stationId;
    char stationName[NAME_LEN];
    uint8_t active;
} Station;

typedef struct Edge
{
    int destination;
    struct Edge *next;
} Edge;

typedef struct
{
    uint32_t vertices;
    Station stations[MAX_STATIONS];
    Edge *adjList[MAX_STATIONS];
} Graph;

Graph *createGraph(void);
int addStation(Graph *graph, const char *name);
void removeStation(Graph *graph, int stationId);
void addConnection(Graph *graph, int src, int dest);
void removeConnection(Graph *graph, int src, int dest);
int findStation(Graph *graph, const char *name);
void displayStations(Graph *graph);
void displayGraph(Graph *graph);
void freeGraph(Graph *graph);

#endif
