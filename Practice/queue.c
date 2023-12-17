#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f, r, size;
    int *arr;
};

void enqueue(struct queue *q, int x)
{
    if (q->r == q->f || q->r == q->size-1)
    {
    }
}