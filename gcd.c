#include<stdio.h>

int gcd(int a,int b)
{
    int x;
    if(b>a)
    {
        return gcd(b,a);
    }
    else if(b == 0)
    {
        return a;
    }
    else
    {
        return (gcd(b,a%b));
    }
}


int main()
{
    int a,b;
    printf("Enter a:");
    scanf("%d",&a);
    printf("\nEnter b:");
    scanf("%d",&b);
    printf("\nThe gcd of %d and %d is :: %d",a,b,gcd(a,b));

    return 0;
}
