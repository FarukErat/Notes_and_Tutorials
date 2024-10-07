#pragma once
#ifndef NETWORK
#define NETWORK

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

// *
// **
// ***
// ****

typedef struct {
    int nodes;
    int** matrix;
} Graph;

Graph* createGraph(int nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = nodes;

    graph->matrix = (int**)malloc(nodes * sizeof(int*));
    for (int i = 0; i < nodes; i++) {
        graph->matrix[i] = (int*)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            graph->matrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    if (u > v) {
        graph->matrix[u][v] = 1;
    } else {
        graph->matrix[v][u] = 1;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->nodes; i++) {
        for (int j = 0; j < graph->nodes; j++) {
            if (i >= j) {
                printf("%d ", graph->matrix[i][j]);
            } else {
                printf("%d ", graph->matrix[j][i]);
            }
        }
        printf("\n");
    }
}

int hasEdge(Graph* graph, int u, int v) {
    if (u > v) {
        return graph->matrix[u][v];
    } else {
        return graph->matrix[v][u];
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->nodes; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

double calculateCompleteness(Graph* graph) {
    int edges = 0;
    for (int i = 0; i < graph->nodes; i++) {
        for (int j = 0; j <= i; j++) {
            edges += graph->matrix[i][j];
        }
    }
    int maxEdges = (graph->nodes * (graph->nodes - 1)) / 2;
    return (double)edges / maxEdges;
}

void calculateDegreeCentrality(Graph* graph, double* centrality) {
    for (int i = 0; i < graph->nodes; i++) {
        centrality[i] = 0;
        for (int j = 0; j < graph->nodes; j++) {
            if (hasEdge(graph, i, j)) {
                centrality[i]++;
            }
        }
    }
}

int shortestPath(Graph* graph, int src, int dest) {
    if (src == dest) return 0;

    int* distance = (int*)malloc(graph->nodes * sizeof(int));
    bool* visited = (bool*)malloc(graph->nodes * sizeof(bool));
    for (int i = 0; i < graph->nodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    int* queue = (int*)malloc(graph->nodes * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = src;
    distance[src] = 0;
    visited[src] = true;

    while (front < rear) {
        int current = queue[front++];

        for (int i = 0; i < graph->nodes; i++) {
            if (hasEdge(graph, current, i) && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;

                queue[rear++] = i;

                if (i == dest) {
                    int dist = distance[i];
                    free(distance);
                    free(visited);
                    free(queue);
                    return dist;
                }
            }
        }
    }

    free(distance);
    free(visited);
    free(queue);

    return INT_MAX;
}

void calculateClosenessCentrality(Graph* graph, double* closeness) {
    for (int i = 0; i < graph->nodes; i++) {
        int totalDistance = 0;
        for (int j = 0; j < graph->nodes; j++) {
            if (i != j) {
                int distance = shortestPath(graph, i, j);
                totalDistance += (distance == INT_MAX) ? 0 : distance;
            }
        }
        closeness[i] = totalDistance > 0 ? (double)(graph->nodes - 1) / totalDistance : 0;
    }
}

#endif // NETWORK
