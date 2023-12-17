#include <stdio.h>
#include <stdlib.h>
struct Stack
{

    int t, size;
    int *arr;
};

int isFull(struct Stack *s)
{
    if (s->t == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *s)
{
    if (s->t == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int a)
{
    if (isFull(s))
    {
        /* code */
        printf("\nStack overflow");
    }
    else
    {
        s->t++;
        s->arr[s->t] = a;
    }
}

void pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nThe Popped element is %d ", s->arr[s->t]);
        s->t--;
    }
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        /* code */
        printf("\nStack is empty");
    }
    else
    {
        for (int i = s->t; i >= 0; i--)
        {
            /* code */
            printf("%d  ", s->arr[i]);
        }
    }
}

void peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nThe element on top is %d ", s->arr[s->t]);
    }
}
int main()
{
    struct Stack s;
    s.t = -1;
    s.size = 5;
    s.arr = (int *)malloc(sizeof(int) * s.size);
    int a, ch;
    while (1)
    {
        /* code */
        printf("\nEnter the option from menu :\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter thye element to push in stack :\n");
            scanf("%d", &a);
            push(&s, a);
            break;

        case 2:
            pop(&s);
            break;

        case 3:
            display(&s);
            break;

        case 4:
            peek(&s);
            break;

        case 5:
            return 0;
            break;

        default:
            printf("Wrong choice");
            break;
        }
    }
    return 0;
}