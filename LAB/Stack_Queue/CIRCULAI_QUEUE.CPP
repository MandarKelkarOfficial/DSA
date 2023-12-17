#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

void addq(int value)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)))
    {
        printf("Queue is full.\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = value;
}

int delq()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return value;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main()
{
    clrscr();

    addq(1);
    addq(2);
    addq(3);
    addq(4);

    printf("Queue after adding elements: ");
    display();

    int deletedValue = delq();
    if (deletedValue != -1)
        printf("Deleted element: %d\n", deletedValue);

    printf("Queue after deleting an element: ");
    display();

    getch();
    return 0;
}
