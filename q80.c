// Day 80 Question 1: Floyd-Warshall Algorithm
// Find shortest paths between all pairs of vertices

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 99999

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int dist[MAX_VERTICES][MAX_VERTICES];
    
    // Initialize distance matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print solution
    printf("Shortest distances between all pairs of vertices:\n");
    printf("     ");
    for (int i = 0; i < vertices; i++) {
        printf("%4d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%4d ", i);
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                printf(" INF ");
            } else {
                printf("%4d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES];
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    // Initialize graph with INF
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }
    
    floydWarshall(graph, vertices);
    
    return 0;
}
