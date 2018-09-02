#include<stdio.h>

int fib(int n)
{
    int a,b;
    if(n==1 || n==0)
    {
        return n;
    }
    else
    {
        a = fib(n-1);
        b = fib(n-2);
        return a+b;
    }
}

int main()
{
    int n;
    printf("Enter the  number  of terms in series:");
    scanf("%d",&n);
    printf("\nThe sum of fibbonacci series is :: %d",fib(n));

    return 0;
}
