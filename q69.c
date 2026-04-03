// Day 69 - Question 1: Dijkstra's Algorithm (Shortest Path)
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minDistance(int V) {
    int min = INF, min_index;
    
    for(int v = 0; v < V; v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void dijkstra(int V, int src) {
    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[src] = 0;
    
    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(V);
        visited[u] = 1;
        
        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INF && 
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < V; i++) {
        if(dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int V, E, src;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    dijkstra(V, src);
    
    return 0;
}
