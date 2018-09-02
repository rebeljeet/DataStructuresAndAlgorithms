#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int *ptr,y;

struct Squeue{
    int arr[MAX];
    int front;
    int rear;
}q;

void sqinsert(struct Squeue *ptr);
int sqdelete(struct Squeue *ptr);
void display(struct Squeue *ptr);

int main(){
int choice;
    q.front=-1;
    q.rear=-1;
    for(;;)
    {
        printf("\nPress 1 to Insert :: Press 2 to Delete :: Press 3 to Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                {
                sqinsert(&q);
                display(&q);
                break;
                }
            case 2:
                {
                sqdelete(&q);
                display(&q);
                break;
                }
            case 3:
                {
                  exit(0);
                }
            default:
                {
                    printf("\nEnter valid choice!!!");
                }
        }
    }
return 0;
}

void display(struct Squeue *ptr)
{
    int i;
    for(i=ptr->front;i<MAX;i++)
    {
        printf("|%d|\t",ptr->arr[i]);
    }
}

void sqinsert(struct Squeue *ptr)
{
    if(ptr->rear == MAX -1)
    {
        printf("\nQueue  Full");
    }
    else
    {
    if(ptr->front == -1)
    {
        ptr->front = 0;
    }

    printf("\nEnter the number you want to enter:");
    scanf("%d",&y);
    ptr->rear = ptr->rear + 1;
    ptr->arr[ptr->rear] = y;
    }
}

int sqdelete(struct Squeue *ptr)
{
    if(ptr->front == -1 || ptr->front > ptr->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        y = ptr->arr[ptr->front];
        ptr->front = ptr->front + 1;
        printf("\nDELETED $$ %d $$\n",y);
    }

   return 0;
}


