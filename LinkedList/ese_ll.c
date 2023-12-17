#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void ll_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        /* code */
        printf(" -->| %d | %d |", ptr->data,ptr->next);
    
        ptr = ptr->next;
    }
}

int main()
{

    struct node *head;
    struct node *head2;
    head = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));

    head->data = 16;
    head->next = head2;

    head2->data = 13;
    head2->next = NULL;

    ll_traversal(head);
    return 0;
}