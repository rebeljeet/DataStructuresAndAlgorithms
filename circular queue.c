#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int *ptr,y;

struct Cqueue{
    int arr[MAX];
    int front;
    int rear;
}Q;

void cqinsert(struct Cqueue *ptr);
int cqdelete(struct Cqueue *ptr);
void display(struct Cqueue *ptr);

int main()
{
    int choice;
    Q.front=-1;
    Q.rear=-1;
    for(;;)
    {
        printf("\nPress 1 to Insert :: Press 2 to Delete :: Press 3 to Display :: Press 0 to Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                {
                cqinsert(&Q);
                break;
                }
            case 2:
                {
                cqdelete(&Q);
                break;
                }
            case 3:
                {
                  display(&Q);
                  break;
                }
            case 4:
                {
                    exit(0);
                    break;
                }
            default:
                {
                    printf("\nEnter valid choice!!!");
                }
        }
    }
}

void cqinsert(struct Cqueue *ptr)
{
    if((ptr->front == 0 && ptr->rear == MAX - 1) || (ptr->front == ptr->rear + 1))
    {
        printf("\nQueue  Full");
    }
    else
    {
    if(ptr->front == -1)
    {
        ptr->front = 0;
    }
    ptr->rear = (ptr->rear+1)%MAX;
    printf("\nEnter the number you want to enter:");
    scanf("%d",&y);
    ptr->arr[ptr->rear] = y;
    printf("\n\tInserted >>> %d",y);
    }

}


int cqdelete(struct Cqueue *ptr)
{
    if(ptr->front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        y = ptr->arr[ptr->front];
            if(ptr->front == ptr->rear)
            {
                ptr->front = -1;
                ptr->rear  = -1;
            }
            else
            {
                ptr->front = (ptr->front + 1)%MAX;
            }
    printf("\nDeleted >>> %d",y);
    return 0;
    }
}

void display(struct Cqueue *ptr)
{
    int i;
    if(ptr->front == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
    printf("Circular Queue Elements are >>> ");
    if (ptr->rear >= ptr->front)
    {
        for (i = ptr->front; i <= ptr->rear; i++)
            printf("{%d} ",ptr->arr[i]);
    }
    else
    {
        for (i = ptr->front; i < MAX; i++)
            printf("{%d} ",ptr->arr[i]);

        for (int i = 0; i <= ptr->rear; i++)
            printf("{%d} ",ptr->arr[i]);
    }
}
}
