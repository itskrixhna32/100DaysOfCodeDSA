// Day 67 - Question 1: Topological Sort (DFS)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int stack[MAX];
int top = -1;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node) {
    visited[node] = 1;
    
    Node* temp = adj[node];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
    
    stack[++top] = node;
}

void topoSort(int V) {
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
        adj[i] = NULL;
    }
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    
    printf("Topological Sort: ");
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    topoSort(V);
    
    return 0;
}
