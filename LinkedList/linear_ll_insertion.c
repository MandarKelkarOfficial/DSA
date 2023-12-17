#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // self reference
};

void LinkedListTraversal(struct Node *node)
{
    while (node != NULL)
    {
        /* code */
        printf("\nElement is %d", node->data);
        node = node->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = data;
    ptr->next = head;
    return ptr;
};

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Linking the two nodes together
    head->data = 7;
    head->next = second;

    second->data = 17;
    second->next = third;

    third->data = 27;
    third->next = NULL;

    LinkedListTraversal(head);

    printf("\n");

    head  = insertAtFirst(head, 44);

    return 0;
}