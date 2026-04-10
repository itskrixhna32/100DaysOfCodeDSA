// Day 76 Question 1: Count Connected Components (Undirected Graph)
// Count the number of connected components in an undirected graph using DFS

#include <stdio.h>
#include <stdlib.h>
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

int countConnectedComponents(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};
    int count = 0;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(graph, visited, i, vertices);
            count++;
        }
    }
    
    return count;
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
    
    int components = countConnectedComponents(graph, vertices);
    printf("Number of connected components: %d\n", components);
    
    return 0;
}
