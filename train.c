#include <stdio.h>
#include <string.h>

#include "train.h"

static TrainInfo trains[] =
{
    {"Chennai","Delhi","Tamil Nadu Express","Daily",33},
    {"Delhi","Mumbai","Rajdhani Express","Daily",16},
    {"Delhi","Kolkata","Poorva Express","Daily",21},
    {"Mumbai","Ahmedabad","Gujarat Express","Daily",7},
    {"Ahmedabad","Jaipur","Ashram Express","Daily",8},
    {"Jaipur","Delhi","Pink City Express","Daily",5},
    {"Delhi","Lucknow","Gomti Express","Daily",6},
    {"Lucknow","Kanpur","Intercity Express","Daily",2},
    {"Kanpur","Patna","Sangam Express","Daily",8},
    {"Patna","Kolkata","Howrah Express","Daily",7},
    {"Hyderabad","Nagpur","Dakshin Express","Daily",10},
    {"Nagpur","Bhopal","GT Express","Daily",7},
    {"Bhopal","Delhi","Shatabdi Express","Daily",8},
    {"Chennai","Vijayawada","Coromandel Express","Daily",7},
    {"Vijayawada","Visakhapatnam","Godavari Express","Daily",6},
    {"Visakhapatnam","Bhubaneswar","Jan Shatabdi","Daily",5},
    {"Bhubaneswar","Kolkata","Falaknuma Express","Daily",6},
    {"Bengaluru","Mysuru","Chamundi Express","Daily",3},
    {"Mumbai","Pune","Deccan Express","Daily",4},
    {"Pune","Indore","Indore Express","Daily",12}
};

#define TRAIN_COUNT (sizeof(trains)/sizeof(trains[0]))

static int isRoute(const char *source, const char *destination, const char *a, const char *b)
{
    return
    (
        (strcmp(source,a) == 0 && strcmp(destination,b) == 0)
        ||
        (strcmp(source,b) == 0 && strcmp(destination,a) == 0)
    );
}

void showAvailableTrains(const char *source, const char *destination)
{
    int found = 0;

    printf("\n=================================\n");
    printf("AVAILABLE TRAINS\n");
    printf("=================================\n");

    for(size_t i = 0U; i < TRAIN_COUNT; i++)
    {
        if(isRoute(source, destination, trains[i].source, trains[i].destination))
        {
            found = 1;

            printf("\nTrain Name   : %s\n", trains[i].trainName);
            printf("Travel Time : %d Hours\n", trains[i].travelTime);
            printf("Running Days: %s\n", trains[i].runningDays);
        }
    }

    if(found == 0)
    {
        printf("\nNo Direct Train Found\n");
        printf("Use BFS Shortest Route Information\n");
    }

    printf("\n=================================\n");
}

void showAlternateRoutes(const char *source, const char *destination)
{
    printf("\n=================================\n");
    printf("ALTERNATE ROUTES\n");
    printf("=================================\n");

    printf("\nSource      : %s\n", source);
    printf("Destination : %s\n", destination);

    printf("\nAlternate Route 1\n");
    printf("%s\n", source);
    printf("-> Intermediate Junction A\n");
    printf("-> Intermediate Junction B\n");
    printf("-> %s\n", destination);

    printf("\nAlternate Route 2\n");
    printf("%s\n", source);
    printf("-> Intermediate Junction X\n");
    printf("-> Intermediate Junction Y\n");
    printf("-> %s\n", destination);

    printf("\n=================================\n");
}
