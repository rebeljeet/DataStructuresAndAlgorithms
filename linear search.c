#include<stdio.h>
main()
{
    int i,n,x;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d:",i + 1);
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the element you want to search for :");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            printf("\nFound element %d at location %d.",x,i+1);
            break;
        }
    }
    return 0;
}
