#include <stdio.h>

#define MAX 20

int stack[MAX];
int top;
int element;
void push()
{
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        printf("Enter the element to push : ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {

        top = stack[MAX - 1];
        top--;
    }
}

void peek()
{
    element = stack[top - 1];
    printf("The top of the stack is %d", element);
}

void display()
{
    for (int i = top - 1; i > 0; i--)
    {
        printf("%d  ", i);
    }
}

void main()
{
    top = -1;
    int j = 0;
    int a;
    while (j < 1)
    {
        /* code */
        printf("Enter the choice from the menu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        scanf("%d", &a);

        switch (a)
        {
            {

            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                j += 2;
                break;

            default:
                break;
            }
        }
    }
}