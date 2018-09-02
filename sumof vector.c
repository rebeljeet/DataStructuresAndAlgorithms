#include<stdio.h>
main()
{
    int n,i,sum = 0;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d:",i + 1);
        scanf("%d",&arr[i]);
    }
    if(n<1){
        printf("Array is empty.");
    }
    for(i=0;i<n;i++)
    {
       sum = sum + arr[i];
    }
    printf("\n The sum of all the elements is %d",sum);
    return 0;
}

