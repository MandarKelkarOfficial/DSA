#include <stdio.h>
#include <conio.h>

#define MAX_CUSTOMERS 10

int front = -1, rear = -1;
int queue[MAX_CUSTOMERS];

void enqueue(int customer) {
    if (rear == MAX_CUSTOMERS - 1) {
        printf("Queue is full. Customer %d needs to wait.\n", customer);
        return;
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = customer;
        printf("Customer %d has joined the queue.\n", customer);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. No customers to serve.\n");
        return;
    } else {
        int customer = queue[front];
        printf("Teller serving Customer %d.\n", customer);

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
        printf("Customers in the queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    clrscr();

    enqueue(1);
    enqueue(2);
    enqueue(3);

    displayQueue();

    dequeue();

    displayQueue();

    getch();
    return 0;
}

