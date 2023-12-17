#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1; // Full
    }
    return 0; // Not full
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1; // Empty
    }
    return 0; // Not empty
}

void push(struct stack *s, int a)
{
    if (isFull(s))
    {
        printf("\nStack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = a;
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("\nThe popped element is %d", s->arr[s->top]);
        s->top--;
    }
}

void peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("\nThe element on top is %d", s->arr[s->top]);
    }
}

void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int c, a;
    struct stack s;

    s.size = 5; // Set the stack size to 5
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    while (1)
    {
        printf("\nEnter the choice number:\n1. Push,\n2. Pop,\n3. Peek,\n4. Display,\n5. Exit: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("\nEnter the element to push: ");
            scanf("%d", &a);
            push(&s, a);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            display(&s);
            break;
        case 5:
            free(s.arr); // Free the dynamically allocated memory
            return 0;
        default:
            printf("Unknown choice");
            break;
        }
    }
}
