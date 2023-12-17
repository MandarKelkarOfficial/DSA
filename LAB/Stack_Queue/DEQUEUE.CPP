#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int deque[MAX_SIZE];

void addFront(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Deque is full.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    deque[front] = value;
}

void addRear(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Deque is full.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

int removeFront() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return -1;
    }

    int value = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    return value;
}

int removeRear() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return -1;
    }

    int value = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }

    return value;
}

void displayDeque() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;
    do {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    clrscr();

    addRear(1);
    addRear(2);
    addFront(3);
    addFront(4);

    printf("Deque after adding elements: ");
    displayDeque();

    int removedFront = removeFront();
    if (removedFront != -1)
        printf("Removed front element: %d\n", removedFront);

    int removedRear = removeRear();
    if (removedRear != -1)
        printf("Removed rear element: %d\n", removedRear);

    printf("Deque after removing elements: ");
    displayDeque();

    getch();
    return 0;
}
