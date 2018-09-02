#include<stdio.h>
main()
{
    int n,i,max;
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
    max = arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    printf("\n The greatest element is %d",max);
    return 0;
}

