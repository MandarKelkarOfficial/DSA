#include <stdio.h>


// Structure to represent a passenger
struct Passenger {
    int ticketNumber;
    char name[50];
    struct Passenger* next;
};

// Structure to represent the queue
struct Queue {
    struct Passenger* front;
    struct Passenger* rear;
};

// Function to create a new passenger
struct Passenger* createPassenger(int ticketNumber, const char* name) {
    struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
    newPassenger->ticketNumber = ticketNumber;
    strcpy(newPassenger->name, name);
    newPassenger->next = NULL;
    return newPassenger;
}

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to insert a new passenger into the queue
void enqueue(struct Queue* queue, int ticketNumber, const char* name) {
    struct Passenger* newPassenger = createPassenger(ticketNumber, name);

    if (queue->rear == NULL) {
        queue->front = queue->rear = newPassenger;
        return;
    }

    queue->rear->next = newPassenger;
    queue->rear = newPassenger;
}

// Function to issue a ticket and remove the passenger from the front
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Passenger* temp = queue->front;
    queue->front = queue->front->next;

    free(temp);
}

// Function to display the passenger at the front
void displayFrontPassenger(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front Passenger: Ticket Number %d, Name: %s\n", queue->front->ticketNumber, queue->front->name);
}

// Function to display the number of passengers left in the queue
int countPassengers(struct Queue* queue) {
    int count = 0;
    struct Passenger* current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    struct Queue* queue = createQueue();
    int choice, ticketNumber;
    char name[50];

    while (1) {
        printf("\n1. Insert a new passenger\n2. Display front passenger\n3. Issue ticket and remove front passenger\n4. Display the number of passengers left in the queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                printf("Enter passenger name: ");
                scanf("%s", name);
                enqueue(queue, ticketNumber, name);
                break;
            case 2:
                displayFrontPassenger(queue);
                break;
            case 3:
                dequeue(queue);
                break;
            case 4:
                printf("Number of passengers left in the queue: %d\n", countPassengers(queue));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}