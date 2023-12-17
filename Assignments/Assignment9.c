#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to initialize a graph with a given number of vertices
struct Graph* initGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src (assuming an undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform BFS traversal on the graph
void BFS(struct Graph* graph, int startVertex) {
    // Initialize visited array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = -1, rear = -1;

    // Enqueue the starting vertex and mark it as visited
    queue[++rear] = startVertex;
    visited[startVertex] = true;

    // Perform BFS
    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Traverse the adjacency list of the current vertex
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                queue[++rear] = adjVertex;
                visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }

    // Free allocated memory
    free(visited);
    free(queue);
}

// Function to display the adjacency list
void displayGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = initGraph(numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List:\n");
    displayGraph(graph);

    printf("\nBFS Traversal:\n");
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS sequence starting from vertex %d: ", startVertex);
    BFS(graph, startVertex);

    // Free allocated memory
    for (int i = 0; i < numVertices; ++i) {
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
