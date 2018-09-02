#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

char opndstk[MAX],symbol,opnd1,opnd2,postfix[MAX],x;
int i,top = -1,ptr = 0,value;

void push(char c);
int pop();
int evaluate(char arr[]);
int check(char c);
int cal(char a,char b,char symbol);
int nextchar(char arr[]);

int main()
{
    printf("Enter the POSTFIX expression :\n");
    gets(postfix);
    symbol = nextchar(postfix);
    evaluate(postfix);
    return 0;
}

void  push(char c)
{
    if(top>MAX)
    {
        printf(" && %d\n",top);
        printf("\nSTACK::OVERFLOW");
    }
    else
    {
    top++;
    opndstk[top] = c;
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
        x = opndstk[top];
        top--;
    }
    return x;
}

int nextchar(char arr[])
{
    ptr++;
    return postfix[ptr - 1];
}


int evaluate(char arr[])
{
    while(symbol != '\0')
    {
        if(check(symbol) == 1)
        {
            push(symbol);
        }
        else
        {
            opnd2 = pop();
            opnd1 = pop();
            value = cal(opnd1,opnd2,symbol);
            push((char)(value + '0'));
        }
        symbol = nextchar(postfix);
    }
    printf("\n\n\tVALUE :: %d",value);
    return 0;
}

int check(char c)
{
    if(isalnum(c) != 0)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}

int cal(char a,char b,char symbol)
{
    value = 0;
    int ia = (int)(a - '0');
    int ib = (int)(b - '0');
    ;
    if(symbol == '+')
    {
        value = ia + ib;
        return value;
    }
    else if(symbol == '-')
    {
        value =  ia - ib;
        return  value;
    }
    else if(symbol == '*')
    {
        value = ia * ib;
        return value;
    }
    else
    {
            value = ia / ib;
            return value;
    }
}
