#include <stdio.h>
#include <stdlib.h>

struct linear_queue
{
    int f, r, size;
    int *arr;
};

int isFull(struct linear_queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct linear_queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct linear_queue *q, int a){
    if(isFull(q)){
        printf("\nQueue Overflow");

    }
    else{
        q->r++;
        q->arr[q->r] = a;
    }
}

void dequeue(struct linear_queue *q){
    if(isEmpty(q)){
        printf("\nQueue Underflow");

    }
    else{
        printf("\nThe Dequeued element is %d", q->arr[q->f]);
        q->f++;
      
    }
}

void display(struct linear_queue *q){
    if(isEmpty(q)){
        printf("\nQueue Underflow");

    }
    else{
        for (int i = q->f+1; i <= q->r; i++)
        {
            printf("%d ",q->arr[i]);
        }
        
      
    }
}


void peek(struct linear_queue *q){
    if(isEmpty(q)){
        printf("\nQueue Underflow");

    }
    else{
        printf("\nThe Front element is %d", q->arr[q->f+1]);
     
      
    }
}

int main(){
    struct linear_queue q;
    int a, ch;
    q.size = 5;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    while (1)
    {
        /* code */
        printf("\nEnter the option from menu :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to enqueue in queue :\n");
            scanf("%d", &a);
            enqueue(&q, a);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            peek(&q);
            break;

        case 5:
            return 0;
            break;

        default:
            printf("Wrong choice");
            break;
        }
    }
    
}