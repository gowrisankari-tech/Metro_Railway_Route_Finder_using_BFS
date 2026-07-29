#ifndef BFS_H
#define BFS_H

#include "../graph/graph.h"

void BFS(Graph *graph, int source, int destination);
void printPath(int parent[], int current, Graph *graph);

#endif
