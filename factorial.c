#include<stdio.h>

int fact(int  n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    printf("Enter the number you want to find the factorial of:");
    scanf("%d",&n);
    
    printf("\nThe factorial of given number is :: %d",fact(n));
    return 0;
}
