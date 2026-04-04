// Day 70 - Question 1: Bellman-Ford Algorithm
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct {
    int u, v, weight;
} Edge;

int dist[MAX];

void bellmanFord(Edge edges[], int V, int E, int src) {
    for(int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            
            if(dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    for(int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        
        if(dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
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
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    Edge edges[E];
    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    bellmanFord(edges, V, E, src);
    
    return 0;
}
