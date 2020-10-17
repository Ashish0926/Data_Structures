#include <stdio.h>
#include <stdlib.h>
void Insert(int arr[], int data, int pos, int n);
void Delete(int arr[], int pos, int *n);
void Display(int arr[], int n);

int main()
{
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    //initializing all array elements with zero
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
    while (1)
    {
        int choice, data, pos;
        printf("\nchoose from the followng options: ");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data and position: ");
            scanf("%d %d", &data, &pos);
            Insert(arr, data, pos, n);
            Display(arr, n);
            break;
        case 2:
            printf("\nEnter position: ");
            scanf("%d", &pos);
            Delete(arr, pos, &n);
            Display(arr, n);
            break;
        case 3:
            printf("\nexiting...");
            exit(0);
        default:
            break;
        }
    }
}

void Insert(int arr[], int data, int pos, int n)
{
    if (pos >= n || pos < 0)
    {
        printf("Invalid Position!\n");
        return;
    }
    arr[pos] = data;
}
void Delete(int arr[], int pos, int *n)
{
    if (pos >= *n || pos < 0)
    {
        printf("Inalid Position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *n = *n-1;
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}