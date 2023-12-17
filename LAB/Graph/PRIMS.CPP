#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int dest, weight;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct MinHeapNode {
    int v;
    int key;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

// Function prototypes
struct Node* createNode(int dest, int weight);
struct Graph* createGraph(int V);
struct MinHeap* createMinHeap(int capacity);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void primMST(struct Graph* graph);

// Function to create a new graph node
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int key) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// Function to create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add an edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to decrease key value in Min Heap
void decreaseKey(struct MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        // Swap with parent
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;

        struct MinHeapNode* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// Function to extract the minimum key node from the Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace the root node with the last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce the size of the heap and heapify the root
    --minHeap->size;
    //heapify(minHeap, 0);

    return root;
}

// Function to print the edges of MST
void printMST(struct MinHeapNode* parent[], int n, struct Graph* graph) {
    printf("Edges of MST using Prim's algorithm:\n");
    for (int i = 1; i < n; ++i)
        printf("%d - %d: %d\n", parent[i]->v, i, graph->array[i].head->weight);
}

// Function to construct MST using Prim's algorithm
void primMST(struct Graph* graph) {
    int V = graph->V;
    struct MinHeap* minHeap = createMinHeap(V);
    struct MinHeapNode* parent[V];

    for (int v = 1; v < V; ++v) {
        parent[v] = NULL;
        minHeap->array[v] = newMinHeapNode(v, INT_MAX);
        minHeap->pos[v] = v;
    }

    // Make the first vertex as the root and decrease its key
    minHeap->array[0] = newMinHeapNode(0, 0);
    minHeap->pos[0] = 0;

    // Initially, the size of Min Heap is V
    minHeap->size = V;

    // Loop to extract the minimum key vertex until the heap becomes empty
    while (minHeap->size > 0) {
        // Extract the vertex with the minimum key value
        struct MinHeapNode* u = extractMin(minHeap);

        // Traverse all adjacent vertices of the extracted vertex and update their key values
        struct Node* current = graph->array[u->v].head;
        while (current != NULL) {
            int v = current->dest;
            if (minHeap->pos[v] < minHeap->size && current->weight < minHeap->array[minHeap->pos[v]]->key) {
                parent[v] = u;
                decreaseKey(minHeap, v, current->weight);
            }
            current = current->next;
        }
    }

    // Print the constructed MST
    printMST(parent, V, graph);

    // Free allocated memory
    free(minHeap->array);
    free(minHeap->pos);
    free(minHeap);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);

    // Free allocated memory
    free(graph->array);
    free(graph);

    return 0;
}
