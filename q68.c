// Day 68 - Question 1: Topological Sort (Kahn's BFS Algorithm)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topoSort(int V) {
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }
    
    printf("Topological Sort: ");
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        
        for(int i = 0; i < V; i++) {
            if(adj[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    for(int i = 0; i < V; i++) {
        indegree[i] = 0;
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
    
    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    
    topoSort(V);
    
    return 0;
}
