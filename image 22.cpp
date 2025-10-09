#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];  
int visited[MAX];
int n;  
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; 
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}

