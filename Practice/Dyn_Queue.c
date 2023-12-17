#include <stdio.h>

#define N 5

int queue[N];
int front, rear;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, element;
    front = rear = -1;
    while (1)
    {
        printf("Enter the choice from the menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
