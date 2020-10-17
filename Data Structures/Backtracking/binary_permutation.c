#include<stdio.h>
void bin(int *A, int n);

void bin(int *A, int n)
{
    static int count;
    if(n<1)
    {
        printf("\n%s",A);
    }
    else
    {
        A[n-1] = '0';
        bin(A,n-1);
        A[n-1] = '1';
        bin(A,n-1);
    }
    
}

void main()
{
    int n;
    printf("\nEnter length of binary num: ");
    scanf("%d",&n);
    int A[n];
    bin(A, n);
}