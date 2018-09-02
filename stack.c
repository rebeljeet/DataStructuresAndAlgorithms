#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int s[MAX],j,top,x,n,i;

void display();
void push();
int pop();
int peep();
void change();



int main()
{
    int choice;
    printf("Enter the number of elements you want to enter in Stack[MAX 100]:");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        printf("\nEnter element %d:",j + 1);
        scanf("%d",&s[j]);
    }
    top = n - 1;
    while(1)
    {
    printf("\nPress 1 for DISPLAY :: Press 2 to PUSH :: Press 3 to POP :: Press 4 to PEEP :: Press 5 to CHANGE :: Press 0 to exit");
    scanf("%d",&choice);
    switch(choice){
        case 0:
            exit(0);
        case 1:
            display();
            break;
        case 2:
            push();
            display();
            break;
        case 3:
            pop();
            display();
            break;
        case 4:
            peep();
            break;
        case 5:
            change();
            display();
            break;
        default:
            printf("Enter Valid choice!!!");
            break;
    }

    }
}

void display()
{
    for(j=top;j>=0;j--)
    {
        printf("\n\t[%d]\n",s[j]);
    }
}

void  push()
{
    if(top>MAX)
    {
        printf("\nSTACK::OVERFLOW");
    }
    else
    {
    top++;
    printf("\nEnter the element you want to enter :");
    scanf("%d",&x);
    s[top] = x;
    }
}

int pop()
{
    if(top<=-1)
    {
        printf("\nSTACK::UNDERFLOW");
    }
    else
    {
        x = s[top];
        top--;
        printf("\nPopped element [%d]\n",x);
    }
    return 0;
}

int peep()
{
    printf("\nEnter the position of the element from the top: ");
    scanf("%d",&i);
    if(top - i + 1 <= 0)
    {
        printf("\nSTACK::UNDERFLOW ON PEEP");
        exit(0);
    }
    else
    {
         printf("\nThe element is: %d",s[top - i + 1]);
    }
}

void change()
{
    printf("\nEnter the position of the element from the top where you want to enter element: ");
    scanf("%d",&i);
    printf("\nEnter the element you want to enter :");
    scanf("%d",&x);
    if(top - i + 1 <= 0)
    {
        printf("\nSTACK::UNDERFLOW ON PEEP");
        exit(0);
    }
    else
    {
        s[top - i + 1] = x;
    }
}
