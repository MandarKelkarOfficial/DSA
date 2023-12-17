#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node** adjacencyList;
};

int* visited;

void dfs(struct Graph* g, int node) {
    printf("%d ", node);
    visited[node] = 1;

    struct Node* current = g->adjacencyList[node];
    while (current != NULL) {
        if (!visited[current->data]) {
            dfs(g, current->data);
        }
        current = current->next;
    }
}

int main() {
    // Your code for accepting graph input goes here

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    printf("Enter the number of nodes: ");
    scanf("%d", &graph->numNodes);

    // Your code for accepting adjacency list goes here

    visited = (int*)calloc(graph->numNodes, sizeof(int));

    printf("DFS Sequence: ");
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            dfs(graph, i);
        }
    }

    free(visited);
    free(graph->adjacencyList);
    free(graph);

    return 0;
}
