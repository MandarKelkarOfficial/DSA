#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a task
struct Task {
    int id;
    int burst_time;
};

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Task* array;
};

// Function to initialize a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (struct Task*)malloc(queue->capacity * sizeof(struct Task));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue a task
void enqueue(struct Queue* queue, struct Task task) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = task;
    queue->size = queue->size + 1;
}

// Function to dequeue a task
struct Task dequeue(struct Queue* queue) {
    struct Task task;
    task.id = -1; // Invalid task ID
    if (isEmpty(queue))
        return task;
    task = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return task;
}

// Function to implement Round Robin scheduling
void roundRobin(struct Task tasks[], int n, int time_quantum) {
    struct Queue* queue = createQueue(MAX_SIZE);

    int currentTime = 0;
    int completedTasks = 0;

    // Array to keep track of completed tasks
    int taskCompleted[n];
    for (int i = 0; i < n; i++) {
        taskCompleted[i] = 0; // Initialize to not completed
    }

    while (completedTasks < n) {
        for (int i = 0; i < n; i++) {
            if (tasks[i].burst_time > 0 && !taskCompleted[i]) {
                if (tasks[i].burst_time <= time_quantum) {
                    currentTime += tasks[i].burst_time;
                    tasks[i].burst_time = 0;
                    printf("Task %d completed at time %d\n", tasks[i].id, currentTime);
                    taskCompleted[i] = 1; // Mark the task as completed
                    completedTasks++;
                } else {
                    currentTime += time_quantum;
                    tasks[i].burst_time -= time_quantum;
                    // Enqueue the task if it's not fully processed
                    enqueue(queue, tasks[i]);
                }
            }
        }

        // Dequeue the tasks and add them back to the queue
        while (!isEmpty(queue)) {
            struct Task task = dequeue(queue);
            enqueue(queue, task);
        }
    }

    free(queue->array);
    free(queue);
}


int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    struct Task tasks[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for task %d: ", i + 1);
        scanf("%d", &tasks[i].burst_time);
        tasks[i].id = i + 1;
    }

    int time_quantum = 5;
    roundRobin(tasks, n, time_quantum);

    return 0;
}

