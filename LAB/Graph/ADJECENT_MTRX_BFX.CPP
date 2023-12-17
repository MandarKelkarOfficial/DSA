#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void bfs(int start) {
    struct Queue* queue = createQueue(numNodes);

    visited[start] = 1;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        for (int i = 0; i < numNodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue->array);
    free(queue);
}

int main() {
    // Your code for accepting graph input goes here

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Your code for accepting adjacency matrix goes here

    printf("BFS Sequence: ");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    return 0;
}
