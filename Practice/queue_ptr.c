#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int a)
{

    if (isFull(q))
    {
        printf("Overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r] = a;
    }
}

void dequeue(struct queue *q)
{
    int a;
    if (isEmpty(q))
    {
        printf("Underflow");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        printf("The dequeued element is %d", a);
    }
}

void display(struct queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
}

int main()
{

    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int c, element;

    while (1)
    {
        printf("\nEnter the choice from the menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &element);
            enqueue(&q, element);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
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