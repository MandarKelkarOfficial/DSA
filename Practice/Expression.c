/*Let's go through the entire code step by step:

1. First, we include the necessary header files, define a constant `MAX_SIZE` for the maximum size of the stack, and define a `Stack` structure to hold the data and top index of the stack.

2. Next, we define various helper functions for stack operations: `initialize`, `isEmpty`, `isFull`, `push`, `pop`, and `peek`. These functions are used to manage the stack required for converting expressions.

3. We define two functions for infix to postfix and infix to prefix conversions: `infixToPostfix` and `infixToPrefix`, respectively. These functions take an infix expression as input and convert it to its corresponding postfix and prefix expressions using a stack.

4. The `isOperator` function checks whether a character is one of the supported operators (+, -, *, /, ^).

5. The `precedence` function returns the precedence of an operator. Operators with higher precedence will be evaluated first during expression conversion.

6. The `postfixToInfix` function takes a postfix expression as input and converts it to its corresponding infix expression using a stack.

7. The `prefixToInfix` function takes a prefix expression as input and converts it to its corresponding infix expression using a stack.

8. In the `main` function, we display a menu with five options: Infix to Postfix, Infix to Prefix, Postfix to Infix, Prefix to Infix, and Exit.

9. The user is prompted to choose one of the options from the menu. Depending on the user's choice, the program reads the input expression (infix, postfix, or prefix) and calls the appropriate function to convert it to the desired format.

10. For options 1 and 2, the program takes an infix expression as input and converts it to its corresponding postfix and prefix expressions, respectively, using the `infixToPostfix` and `infixToPrefix` functions. The converted expressions are then displayed.

11. For options 3 and 4, the program takes a postfix or prefix expression as input and converts it to its corresponding infix expression using the `postfixToInfix` and `prefixToInfix` functions, respectively. The converted infix expression is then displayed.

12. Option 5 allows the user to exit the program.

Overall, the program demonstrates menu-driven functionality to convert infix expressions to postfix and prefix and vice versa using a stack-based approach. It uses functions to handle the conversions, and the stack is used to manage intermediate steps during the conversion process.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char element)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++(stack->top)] = element;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[(stack->top)--];
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->top];
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack)))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }

        i++;
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void infixToPrefix(char *infix, char *prefix)
{
    // Reverse the infix expression
    int len = strlen(infix);
    char reversedInfix[MAX_SIZE];
    for (int i = 0; i < len; i++)
    {
        reversedInfix[i] = infix[len - 1 - i];
    }
    reversedInfix[len] = '\0';

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < len; i++)
    {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }

    // Convert reversed infix to postfix
    char reversedPostfix[MAX_SIZE];
    infixToPostfix(reversedInfix, reversedPostfix);

    // Reverse the postfix expression to get the prefix expression
    int j = 0;
    for (int i = strlen(reversedPostfix) - 1; i >= 0; i--)
    {
        prefix[j++] = reversedPostfix[i];
    }
    prefix[j] = '\0';
}

void postfixToInfix(char *postfix, char *infix)
{
    Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        if (isalnum(ch))
        {
            char operand[2] = {ch, '\0'};
            push(&stack, operand[0]);
        }
        else if (isOperator(ch))
        {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);
            char temp[MAX_SIZE];
            temp[0] = '(';
            temp[1] = operand2;
            temp[2] = ch;
            temp[3] = operand1;
            temp[4] = ')';
            temp[5] = '\0';
            push(&stack, temp[0]);
            push(&stack, temp[1]);
            push(&stack, temp[2]);
            push(&stack, temp[3]);
            push(&stack, temp[4]);
        }

        i++;
    }

    while (!isEmpty(&stack))
    {
        infix[j++] = pop(&stack);
    }

    infix[j] = '\0';
}

void prefixToInfix(char *prefix, char *infix)
{
    Stack stack;
    initialize(&stack);
    int len = strlen(prefix);

    // Reverse the prefix expression
    char reversedPrefix[MAX_SIZE];
    for (int i = 0; i < len; i++)
    {
        reversedPrefix[i] = prefix[len - 1 - i];
    }
    reversedPrefix[len] = '\0';

    for (int i = 0; i < len; i++)
    {
        char ch = reversedPrefix[i];

        if (isalnum(ch))
        {
            char operand[2] = {ch, '\0'};
            push(&stack, operand[0]);
        }
        else if (isOperator(ch))
        {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);
            char temp[MAX_SIZE];
            temp[0] = '(';
            temp[1] = operand1;
            temp[2] = ch;
            temp[3] = operand2;
            temp[4] = ')';
            temp[5] = '\0';
            push(&stack, temp[0]);
            push(&stack, temp[1]);
            push(&stack, temp[2]);
            push(&stack, temp[3]);
            push(&stack, temp[4]);
        }
    }

    while (!isEmpty(&stack))
    {
        infix[len - 1 - stack.top] = pop(&stack);
    }

    infix[len] = '\0';
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    char prefix[MAX_SIZE];
    int choice;

    printf("Menu:\n");
    printf("1. Infix to Postfix\n");
    printf("2. Infix to Prefix\n");
    printf("3. Postfix to Infix\n");
    printf("4. Prefix to Infix\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice)
        {
        case 1:
            printf("Enter the infix expression: ");
            gets(infix);
            infixToPostfix(infix, postfix);
            printf("Postfix expression: %s\n", postfix);
            break;

        case 2:
            printf("Enter the infix expression: ");
            gets(infix);
            infixToPrefix(infix, prefix);
            printf("Prefix expression: %s\n", prefix);
            break;

        case 3:
            printf("Enter the postfix expression: ");
            gets(postfix);
            postfixToInfix(postfix, infix);
            printf("Infix expression: %s\n", infix);
            break;

        case 4:
            printf("Enter the prefix expression: ");
            gets(prefix);
            prefixToInfix(prefix, infix);
            printf("Infix expression: %s\n", infix);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
