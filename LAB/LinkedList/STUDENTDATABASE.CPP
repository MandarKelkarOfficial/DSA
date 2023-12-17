#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    struct Student* next;
};

struct Student* createNode(int roll, const char* name) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

struct Student* insertFront(struct Student* head, int roll, const char* name) {
    struct Student* newNode = createNode(roll, name);
    newNode->next = head;
    return newNode;
}

void display(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll: %d, Name: %s\n", current->roll, current->name);
        current = current->next;
    }
}

// Implement reverse display
void reverseDisplay(struct Student* head) {
    // Implementation of reverse display here
}

struct Student* insertAfter(struct Student* head, int roll, const char* name, int afterRoll) {
    // Implementation of insertion after a specific roll number
}

struct Student* deleteNode(struct Student* head, int roll) {
    // Implementation of deletion of a node with a specific roll number
}

void freeList(struct Student* head) {
    // Implementation to free the allocated memory for the list
}

int main() {
    clrscr();

    struct Student* head = NULL;

    // Insert some students
    head = insertFront(head, 101, "John");
    head = insertFront(head, 102, "Alice");
    head = insertFront(head, 103, "Bob");

    // Display the list
    printf("Original List:\n");
    display(head);

    // Insert after a specific roll number
    head = insertAfter(head, 104, "Charlie", 102);

    // Display the list after insertion
    printf("\nList after insertion:\n");
    display(head);

    // Delete a node with a specific roll number
    head = deleteNode(head, 102);

    // Display the list after deletion
    printf("\nList after deletion:\n");
    display(head);

    // Free the allocated memory for the list
    freeList(head);

    getch();
    return 0;
}
