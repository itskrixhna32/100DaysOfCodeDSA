// Day 77 Question 1: Check if Graph is Connected
// Check if an undirected graph is connected using DFS

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[], int v, int vertices) {
    visited[v] = true;
    
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, visited, i, vertices);
        }
    }
}

bool isConnected(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};
    
    // Start DFS from vertex 0
    DFS(graph, visited, 0, vertices);
    
    // Check if all vertices were visited
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }
    
    if (isConnected(graph, vertices)) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }
    
    return 0;
}
