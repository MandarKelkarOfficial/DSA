#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int passenger) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot add more passengers.\n");
        return;
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = passenger;
        printf("Passenger %d added to the queue.\n", passenger);
    }
}

void issueTicket() {
    if (front == -1) {
        printf("Queue is empty. No passengers to issue tickets.\n");
        return;
    } else {
        printf("Ticket issued to Passenger %d.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void displayQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    } else {
        printf("Passengers in the queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    clrscr();

    enqueue(101);
    enqueue(102);
    enqueue(103);

    displayQueue();

    issueTicket();

    displayQueue();

    getch();
    return 0;
}
