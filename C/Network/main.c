#include "network.h"

int main() {
    int numNodes = 5;
    Graph* graph = createGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("Graph adjacency matrix:\n");
    printGraph(graph);

    double completeness = calculateCompleteness(graph);
    printf("Completeness: %.2f\n", completeness);

    double* degreeCentrality = (double*)malloc(numNodes * sizeof(double));
    calculateDegreeCentrality(graph, degreeCentrality);
    printf("Degree Centrality:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %.0f\n", i, degreeCentrality[i]);
    }
    free(degreeCentrality);

    double* closenessCentrality = (double*)malloc(numNodes * sizeof(double));
    calculateClosenessCentrality(graph, closenessCentrality);
    printf("Closeness Centrality:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %.2f\n", i, closenessCentrality[i]);
    }
    free(closenessCentrality);

    freeGraph(graph);

    return 0;
}

/*
Output:

Graph adjacency matrix:
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 0
0 0 1 0 0
Completeness: 0.50
Degree Centrality:
Node 0: 2
Node 1: 3
Node 2: 3
Node 3: 1
Node 4: 1
Closeness Centrality:
Node 0: 0.67
Node 1: 0.80
Node 2: 0.80
Node 3: 0.50
Node 4: 0.50
*/
