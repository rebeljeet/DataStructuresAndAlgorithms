#include<stdio.h>
main()
{
    int n,i,j,k,sum;
    printf("Enter the order of array:");
    scanf("%d",&n);
    int A[n][n],B[n][n],C[n][n];
    printf("\nEnter matrix A:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter matrix B\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum = 0;
            for(k=0;k<n;k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    printf("\nThe multiplication of matrix A and B is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
         printf("\t%d",C[i][j]);
         if(j==n-1)
            printf("\n");
        }
    }
    return 0;
}
