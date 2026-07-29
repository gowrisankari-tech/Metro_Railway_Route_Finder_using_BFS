#include <stdio.h>
#include <string.h>

#include "user.h"
#include "../bfs/bfs.h"
#include "../train/train.h"

/* =========================================================
   STATION CLASSIFICATION (Metro vs Railway)
   These lists mirror the names added in
   utils.c -> initializeDefaultNetwork(). If you add more
   Metro or Railway stations there, add their names here too.
   ========================================================= */

static const char *metroStations[] =
{
    "Central Metro", "Egmore Metro", "Nehru Park", "Kilpauk",
    "Shenoy Nagar", "Anna Nagar East", "Koyambedu", "Vadapalani",
    "Ashok Nagar", "Alandur Metro", "Government Estate", "LIC",
    "Thousand Lights", "AG-DMS", "Teynampet", "Nandanam",
    "Saidapet", "Little Mount", "Guindy Metro", "Airport"
};

#define METRO_COUNT (sizeof(metroStations) / sizeof(metroStations[0]))

static const char *railwayStations[] =
{
    "Chennai", "Bengaluru", "Mysuru", "Hyderabad", "Vijayawada",
    "Visakhapatnam", "Nagpur", "Bhopal", "Indore", "Pune",
    "Mumbai", "Ahmedabad", "Jaipur", "Delhi", "Lucknow",
    "Kanpur", "Patna", "Kolkata", "Bhubaneswar", "Coimbatore"
};

#define RAILWAY_COUNT (sizeof(railwayStations) / sizeof(railwayStations[0]))

static int isMetroStation(const char *name)
{
    for(size_t i = 0U; i < METRO_COUNT; i++)
    {
        if(strcmp(name, metroStations[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

static int isRailwayStation(const char *name)
{
    for(size_t i = 0U; i < RAILWAY_COUNT; i++)
    {
        if(strcmp(name, railwayStations[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

static void viewMetroStations(void)
{
    printf("\n===== METRO STATIONS =====\n");

    for(size_t i = 0U; i < METRO_COUNT; i++)
    {
        printf("%2zu. %s\n", i + 1U, metroStations[i]);
    }
}

static void readLine(char *buffer, size_t size)
{
    fgets(buffer, (int)size, stdin);

    buffer[strcspn(buffer, "\n")] = '\0';
}

/* =========================================================
   METRO MENU
   ========================================================= */

static void metroMenu(Graph *graph)
{
    int choice;

    char source[50];
    char destination[50];

    while(1)
    {
        printf("\n===== METRO MENU =====\n");
        printf("1. View Metro Stations\n");
        printf("2. Find Shortest Route\n");
        printf("3. Back\n");

        printf("\nEnter Choice : ");

        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
            {
                viewMetroStations();
                break;
            }

            case 2:
            {
                printf("Source Metro Station : ");
                readLine(source, sizeof(source));

                printf("Destination Metro Station : ");
                readLine(destination, sizeof(destination));

                if((isMetroStation(source) == 0) ||
                   (isMetroStation(destination) == 0))
                {
                    printf("\nInvalid Metro Station Name\n");
                    printf("(Choose option 1 to view valid Metro stations)\n");
                    break;
                }

                int src = findStation(graph, source);
                int dest = findStation(graph, destination);

                if((src == -1) || (dest == -1))
                {
                    printf("\nStation Not Found In Network\n");
                    break;
                }

                /* BFS() prints the route plus the total
                   station count and hop count. */
                BFS(graph, src, dest);

                break;
            }

            case 3:

                return;

            default:

                printf("\nInvalid Choice\n");
        }
    }
}

/* =========================================================
   RAILWAY MENU
   ========================================================= */

static void railwayMenu(Graph *graph)
{
    int choice;

    char source[50];
    char destination[50];

    while(1)
    {
        printf("\n===== RAILWAY MENU =====\n");
        printf("1. Find Shortest Route\n");
        printf("2. View Alternate Route\n");
        printf("3. View Available Trains\n");
        printf("4. Back\n");

        printf("\nEnter Choice : ");

        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
            {
                printf("Source Station : ");
                readLine(source, sizeof(source));

                printf("Destination Station : ");
                readLine(destination, sizeof(destination));

                if((isRailwayStation(source) == 0) ||
                   (isRailwayStation(destination) == 0))
                {
                    printf("\nInvalid Railway Station Name\n");
                    break;
                }

                int src = findStation(graph, source);
                int dest = findStation(graph, destination);

                if((src == -1) || (dest == -1))
                {
                    printf("\nStation Not Found In Network\n");
                    break;
                }

                BFS(graph, src, dest);

                break;
            }

            case 2:
            {
                printf("Source : ");
                readLine(source, sizeof(source));

                printf("Destination : ");
                readLine(destination, sizeof(destination));

                showAlternateRoutes(source, destination);

                break;
            }

            case 3:
            {
                printf("Source : ");
                readLine(source, sizeof(source));

                printf("Destination : ");
                readLine(destination, sizeof(destination));

                showAvailableTrains(source, destination);

                break;
            }

            case 4:

                return;

            default:

                printf("\nInvalid Choice\n");
        }
    }
}

/* =========================================================
   TOP-LEVEL USER MENU
   ========================================================= */

void userMenu(Graph *graph)
{
    int choice;

    while(1)
    {
        printf("\n===== USER MENU =====\n");
        printf("1. Metro\n");
        printf("2. Railway\n");
        printf("3. Exit\n");

        printf("\nEnter Choice : ");

        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:

                metroMenu(graph);
                break;

            case 2:

                railwayMenu(graph);
                break;

            case 3:

                return;

            default:

                printf("\nInvalid Choice\n");
        }
    }
}
