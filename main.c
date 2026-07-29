#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph/graph.h"
#include "utils/utils.h"
#include "logger/logger.h"
#include "memory/memory.h"
#include "admin/admin.h"
#include "user/user.h"

int main(void)
{
    Graph *graph;

    int choice;

    memoryInit();

    graph = createGraph();

    if(graph == NULL)
    {
        printf("Graph Creation Failed\n");
        return 1;
    }

    logInfo("Application Started");

    initializeDefaultNetwork(graph);

    printf("\n");
    printf("====================================\n");
    printf("STRUCTURE PADDING DEMONSTRATION\n");
    printf("====================================\n");

    printf("Normal Structure Size : %zu Bytes\n", sizeof(NormalStation));
    printf("Packed Structure Size : %zu Bytes\n", sizeof(PackedStation));
    printf("Station Structure Size: %zu Bytes\n", sizeof(Station));

    printf("====================================\n");

    while(1)
    {
        printf("\n");
        printf("=====================================\n");
        printf(" METRO RAILWAY ROUTE FINDER\n");
        printf("=====================================\n");

        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");

        printf("=====================================\n");

        printf("\nEnter Choice : ");

        scanf("%d", &choice);

        clearInputBuffer();

        switch(choice)
        {
            case 1:
            {
                char username[20];
                char password[20];

                printf("\nAdmin Username : ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';

                printf("Admin Password : ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';

                if((strcmp(username, "admin") == 0) && (strcmp(password, "admin123") == 0))
                {
                    printf("\nLogin Successful\n");
                    logInfo("Admin Login Successful");
                    adminMenu(graph);
                }
                else
                {
                    printf("\nInvalid Credentials\n");
                    logWarning("Admin Login Failed");
                }

                break;
            }

            case 2:

                printf("\nUser Login Successful\n");
                logInfo("User Login Successful");
                userMenu(graph);
                break;

            case 3:

                printf("\nClosing Application...\n");
                freeGraph(graph);
                displayMemoryStatistics();
                logInfo("Application Closed");
                printf("\nProgram Terminated Successfully\n");
                return 0;

            default:

                printf("\nInvalid Choice\n");
                logWarning("Invalid Main Menu Choice");
        }
    }

    return 0;
}
