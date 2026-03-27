#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};
    int u, v;
    int isDirected;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Directed or Undirected
    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &isDirected);

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;

        // If undirected, add reverse edge
        if (!isDirected) {
            graph[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}