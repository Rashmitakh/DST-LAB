/* 
9 b) Write a program to check whether given graph is
connected or not using DFS method.
*/

#include <stdio.h>

#define MAX 10

int visited[MAX];

void DFS(int graph[MAX][MAX], int n, int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(graph, n, 0);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is connected.\n");
    else
        printf("Graph is not connected.\n");

    return 0;
}

/*
Sample Output:
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
Graph is connected.
*/
