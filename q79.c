// Day 79 Question 1: Single Source Shortest Path using Dijkstra's Algorithm
// Find shortest paths from a source vertex to all other vertices

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int minDistance(int dist[], bool visited[], int vertices) {
    int min = INF, minIndex;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int vertices, edges, src;
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
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    dijkstra(graph, src, vertices);
    
    return 0;
}
