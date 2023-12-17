#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Your code for accepting graph input goes here

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Your code for accepting adjacency matrix goes here

    printf("DFS Sequence: ");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}
