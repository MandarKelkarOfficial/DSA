#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Graph {
    int numNodes;
    struct Node** adjacencyList;
};

int* visited;

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = item;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    }

    int item = queue->front->data;
    struct QueueNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return item;
}

void bfs(struct Graph* g, int start) {
    struct Queue* queue = createQueue();

    visited[start] = 1;
    enqueue(queue, start);

    while (queue->front != NULL) {
        int current = dequeue(queue);
        printf("%d ", current);

        struct Node* temp = g->adjacencyList[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                enqueue(queue, temp->data);
            }
            temp = temp->next;
        }
    }

    free(queue);
}

int main() {
    // Your code for accepting graph input goes here

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    printf("Enter the number of nodes: ");
    scanf("%d", &graph->numNodes);

    // Your code for accepting adjacency list goes here

    visited = (int*)calloc(graph->numNodes, sizeof(int));

    printf("BFS Sequence: ");
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            bfs(graph, i);
        }
    }

    free(visited);
    free(graph->adjacencyList);
    free(graph);

    return 0;
}
