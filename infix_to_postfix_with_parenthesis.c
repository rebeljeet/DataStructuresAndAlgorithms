#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int i,top = -1,n,r,rank,ptr,j = 0;
char c,s[MAX],x,polish[MAX],next,infix[MAX],temp;

void push(char c);
int getrank(char c);
int f(char c);
int g(char c);
int nextchar(char arr[MAX]);
int pop();
void display();


int main()
{
    ptr = 0;
    printf("Enter the INFIX expression : (Append INFIX expression with ')' )\n");
    gets(infix);
    push('(');
    rank = 0;
    next = nextchar(infix);
    while(next != '\0')
    {
        while(f(next) < g(s[top]))
        {
            temp = pop();
            polish[j] = temp;
            j++;
            rank = rank + getrank(temp);
            if(rank < 1)
            {
                printf("\nINVALID");
                exit(0);
            }
        }
        if(f(next)  != g(s[top]))
        {
            push(next);
        }
        else
        {
            pop();
        }
        next = nextchar(infix);
    }
    if(rank == 1)
    {
        printf("\nVALID\n\n\tPOSTFIX :: ");
        displaypolish();
        printf("\n\n");
    }
    else
    {
        printf("\nINVALID");
    }

}

int getrank(char c)
{
    if(isalnum(c)!= 0)
    {
        r = 1;
    }
    else
    {
        r = -1;
    }
    return r;
}

int f(char c)
{
    if(isalnum(c) != 0)
    {
        return(7);
    }
    else if(c == '+' || c == '-')
    {
        return(1);
    }
    else if(c == '*' || c == '/')
    {
        return(3);
    }
    else if(c == '^' || c == '$')
    {
        return(6);
    }
    else if(c == '(')
    {
        return(9);
    }
    else
    {
        return(0);
    }
}

int g(char c)
{
    if(isalnum(c) != 0)
    {
        return 8;
    }
    else if(c == '+' || c == '1')
    {
        return 2;
    }
    else if(c == '*' || c == '/')
    {
        return 4;
    }
    else if(c == '^' || c == '$')
    {
        return 5;
    }
    else if(c == '(')
    {
        return 0;
    }
}

void  push(char c)
{
    if(top>MAX)
    {
        printf("\nSTACK::OVERFLOW");
    }
    else
    {
    top++;
    s[top] = c;
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
    }
    return x;
}

int nextchar(char arr[MAX])
{
    ptr++;
    return infix[ptr - 1];
}

void displaypolish()
{
    for(i=0;i<ptr;i++)
    {
        printf("%c",polish[i]);
    }
}



