#include <stdio.h>
#include <string.h>

#include "admin.h"
#include "../bfs/bfs.h"
#include "../utils/utils.h"
#include "../logger/logger.h"

void adminMenu(Graph *graph)
{
    int choice;

    char source[50];
    char destination[50];

    while(1)
    {
        showMenu();

        printf("\nEnter Choice : ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:

                displayStations(graph);
                break;

            case 2:

                displayGraph(graph);
                break;

            case 3:
            {
                printf("Source : ");
                fgets(source, sizeof(source), stdin);
                source[strcspn(source, "\n")] = '\0';

                printf("Destination : ");
                fgets(destination, sizeof(destination), stdin);
                destination[strcspn(destination, "\n")] = '\0';

                int src = findStation(graph, source);
                int dest = findStation(graph, destination);

                if((src == -1) || (dest == -1))
                {
                    printf("\nInvalid Station\n");
                    break;
                }

                BFS(graph, src, dest);

                break;
            }

            case 4:

                printf("\nSave Network: not yet implemented.\n");
                logWarning("Save Network Not Implemented");
                break;

            case 5:

                printf("\nLoad Network: not yet implemented.\n");
                logWarning("Load Network Not Implemented");
                break;

            case 6:

                return;

            default:

                printf("\nInvalid Choice\n");
                logWarning("Invalid Admin Menu Choice");
        }
    }
}
