#include<stdio.h>

int mul(int a,int b)
{
    if(b == 1)
    {
        return a;
    }
    else
    {
        return (mul(a,b-1)+a);
    }
}

int main()
{
    int a,b;
    printf("Enter a:");
    scanf("%d",&a);
    printf("\nEnter b:");
    scanf("%d",&b);
    printf("\nThe multiplication of %d and %d is :: %d",a,b,mul(a,b));
    return 0;
}
