#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char items[MAX_SIZE][MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char item[]) {
    strcpy(s->items[++(s->top)], item);
}

// Function to pop an element from the stack
char* pop(struct Stack *s) {
    return s->items[(s->top)--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert a prefix expression to infix expression
char* prefixToInfix(char prefix[]) {
    struct Stack s;
    initialize(&s);
    int len = strlen(prefix);
    char result[MAX_SIZE] = "";

    for (int i = len - 1; i >= 0; i--) {
        char symbol[2] = {prefix[i], '\0'};

        if (isalnum(prefix[i])) {
            push(&s, symbol);
        } else if (isOperator(prefix[i])) {
            char op1[MAX_SIZE], op2[MAX_SIZE];
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            snprintf(result, sizeof(result), "(%s%s%s)", op1, symbol, op2);
            push(&s, result);
        }
    }

    return pop(&s);
}

// Function to evaluate an infix expression
int evaluateInfix(char infix[]) {
    struct Stack s;
    initialize(&s);
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char symbol[2] = {infix[i], '\0'};

        if (isdigit(infix[i])) {
            push(&s, symbol);
        } else if (isOperator(infix[i])) {
            int op2 = atoi(pop(&s));
            int op1 = atoi(pop(&s));
            int result;
            switch (symbol[0]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            snprintf(symbol, sizeof(symbol), "%d", result);
            push(&s, symbol);
        }
    }

    return atoi(pop(&s));
}

int main() {
    char prefix[MAX_SIZE];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    char *infix = prefixToInfix(prefix);
    printf("Infix expression: %s\n", infix);

    int result = evaluateInfix(infix);
    printf("Result: %d\n", result);

    return 0;
}
