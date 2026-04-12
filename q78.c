// Day 78 Question 1: Minimum Spanning Tree using Prim's Algorithm
// Find MST of a weighted undirected graph using Prim's Algorithm

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, minIndex;
    
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Edge \tWeight\n");
    int totalWeight = 0;
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, vertices);
}

int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    primMST(graph, vertices);
    
    return 0;
}
