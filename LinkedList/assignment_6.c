#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to calculate the factorial of a number using a stack
int factorial(int n) {
    struct Stack stack;
    initializeStack(&stack);

    int result = 1;
    for (int i = 1; i <= n; i++) {
        push(&stack, i);
    }

    while (!isEmpty(&stack)) {
        result *= pop(&stack);
    }

    return result;
}

// Function to convert a decimal number to binary using a stack
void decimalToBinary(int decimal) {
    struct Stack stack;
    initializeStack(&stack);

    if (decimal == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    while (decimal > 0) {
        push(&stack, decimal % 2);
        decimal /= 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Decimal to Binary Conversion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is: %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                decimalToBinary(n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
