#include <stdio.h>

#include "utils.h"

void clearInputBuffer(void)
{
    int ch;

    while(((ch = getchar()) != '\n') && (ch != EOF))
    {
        /* Empty */
    }
}

void showMenu(void)
{
    printf("\n");
    printf("=====================================\n");
    printf(" METRO RAILWAY ROUTE FINDER USING BFS\n");
    printf("=====================================\n");

    printf("1. View Stations\n");
    printf("2. Display Network\n");
    printf("3. Find Shortest Route\n");
    printf("4. Save Network\n");
    printf("5. Load Network\n");
    printf("6. Exit\n");

    printf("=====================================\n");
}

void initializeDefaultNetwork(Graph *graph)
{
    /* =========================
       GREEN LINE METRO
       ========================= */

    int centralMetro      = addStation(graph, "Central Metro");
    int egmoreMetro       = addStation(graph, "Egmore Metro");
    int nehruPark         = addStation(graph, "Nehru Park");
    int kilpauk           = addStation(graph, "Kilpauk");
    int shenoyNagar       = addStation(graph, "Shenoy Nagar");
    int annaNagarEast     = addStation(graph, "Anna Nagar East");
    int koyambedu         = addStation(graph, "Koyambedu");
    int vadapalani        = addStation(graph, "Vadapalani");
    int ashokNagar        = addStation(graph, "Ashok Nagar");
    int alandurMetro      = addStation(graph, "Alandur Metro");

    /* =========================
       BLUE LINE METRO
       ========================= */

    int govtEstate        = addStation(graph, "Government Estate");
    int lic               = addStation(graph, "LIC");
    int thousandLights    = addStation(graph, "Thousand Lights");
    int agDms             = addStation(graph, "AG-DMS");
    int teynampet         = addStation(graph, "Teynampet");
    int nandanam          = addStation(graph, "Nandanam");
    int saidapet          = addStation(graph, "Saidapet");
    int littleMount       = addStation(graph, "Little Mount");
    int guindyMetro       = addStation(graph, "Guindy Metro");
    int airport           = addStation(graph, "Airport");

    /* =========================
       RAILWAY NETWORK
       ========================= */

    int chennai         = addStation(graph, "Chennai");
    int bengaluru       = addStation(graph, "Bengaluru");
    int mysuru          = addStation(graph, "Mysuru");
    int hyderabad       = addStation(graph, "Hyderabad");
    int vijayawada      = addStation(graph, "Vijayawada");
    int visakhapatnam   = addStation(graph, "Visakhapatnam");
    int nagpur          = addStation(graph, "Nagpur");
    int bhopal          = addStation(graph, "Bhopal");
    int indore          = addStation(graph, "Indore");
    int pune            = addStation(graph, "Pune");
    int mumbai          = addStation(graph, "Mumbai");
    int ahmedabad       = addStation(graph, "Ahmedabad");
    int jaipur          = addStation(graph, "Jaipur");
    int delhi           = addStation(graph, "Delhi");
    int lucknow         = addStation(graph, "Lucknow");
    int kanpur          = addStation(graph, "Kanpur");
    int patna           = addStation(graph, "Patna");
    int kolkata         = addStation(graph, "Kolkata");
    int bhubaneswar     = addStation(graph, "Bhubaneswar");
    int coimbatore      = addStation(graph, "Coimbatore");

    /* =========================
       GREEN LINE CONNECTIONS
       ========================= */

    addConnection(graph, centralMetro, egmoreMetro);
    addConnection(graph, egmoreMetro, nehruPark);
    addConnection(graph, nehruPark, kilpauk);
    addConnection(graph, kilpauk, shenoyNagar);
    addConnection(graph, shenoyNagar, annaNagarEast);
    addConnection(graph, annaNagarEast, koyambedu);
    addConnection(graph, koyambedu, vadapalani);
    addConnection(graph, vadapalani, ashokNagar);
    addConnection(graph, ashokNagar, alandurMetro);

    /* =========================
       BLUE LINE CONNECTIONS
       ========================= */

    addConnection(graph, centralMetro, govtEstate);
    addConnection(graph, govtEstate, lic);
    addConnection(graph, lic, thousandLights);
    addConnection(graph, thousandLights, agDms);
    addConnection(graph, agDms, teynampet);
    addConnection(graph, teynampet, nandanam);
    addConnection(graph, nandanam, saidapet);
    addConnection(graph, saidapet, littleMount);
    addConnection(graph, littleMount, guindyMetro);
    addConnection(graph, guindyMetro, alandurMetro);
    addConnection(graph, alandurMetro, airport);

    /* =========================
       RAILWAY LINE CONNECTIONS
       ========================= */

    /* Shortest Chennai -> Delhi Route */

    addConnection(graph, chennai, vijayawada);
    addConnection(graph, vijayawada, nagpur);
    addConnection(graph, nagpur, delhi);

    /* Alternate Route 1 */

    addConnection(graph, chennai, bengaluru);
    addConnection(graph, bengaluru, pune);
    addConnection(graph, pune, mumbai);
    addConnection(graph, mumbai, delhi);

    /* Alternate Route 2 */

    addConnection(graph, chennai, hyderabad);
    addConnection(graph, hyderabad, bhopal);
    addConnection(graph, bhopal, jaipur);
    addConnection(graph, jaipur, delhi);

    /* Eastern Route */

    addConnection(graph, delhi, lucknow);
    addConnection(graph, lucknow, kanpur);
    addConnection(graph, kanpur, patna);
    addConnection(graph, patna, kolkata);

    /* Coastal Route */

    addConnection(graph, kolkata, bhubaneswar);
    addConnection(graph, bhubaneswar, visakhapatnam);
    addConnection(graph, visakhapatnam, vijayawada);

    /* Western Route */

    addConnection(graph, pune, ahmedabad);
    addConnection(graph, ahmedabad, jaipur);

    /* Central Route */

    addConnection(graph, hyderabad, nagpur);
    addConnection(graph, indore, bhopal);
    addConnection(graph, indore, nagpur);

    /* South Route */

    addConnection(graph, chennai, coimbatore);
    addConnection(graph, coimbatore, bengaluru);
    addConnection(graph, bengaluru, mysuru);

    /* =========================
       INTERCHANGE
       ========================= */

    addConnection(graph, centralMetro, chennai);
}
