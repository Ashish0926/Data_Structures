#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayQueue
{
    int front, rear, capacity;
    int *array;
}CircularArrayQ;

CircularArrayQ *CreateQueue(int size)
{
    CircularArrayQ *Q = malloc(sizeof(CircularArrayQ));
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(sizeof(int)*Q->capacity);
    return Q;
}
int isEmpty(CircularArrayQ *Q)
{
    return (Q->front == -1);
}
int isFull(CircularArrayQ *Q)
{
    return (Q->rear == Q->capacity-1 && Q->front == 0);
}
void EnQue(CircularArrayQ *Q, int data)
{
    if(isFull(Q))
    {
        printf("Queue Overflow");
        return;
    }
    if(Q->front == -1 && Q->rear == -1)
    {
        Q->front = Q->rear = 0;
    }
    else if(Q->rear == Q->capacity -1)
    {
        Q->rear = 0;
    }
    else
    {
        Q->rear = Q->rear + 1;
    }
    Q->array[Q->rear] = data;
    printf("Inserted %d",Q->array[Q->rear]);
    if(isFull(Q))
    {
        printf("\nQueue is now full! You cannot insert further");
        return;
    }
}
int DeQue(CircularArrayQ *Q)
{
    int data;
    if(isEmpty(Q))
    {
        return -1;
    }
    data = Q->array[Q->front];
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
    }
    else
    {
        Q->front = Q->front + 1;
    }
    return data;
}
void main()
{
    CircularArrayQ *Q = NULL;
    int choice, data, size;
    while (1)
    {
        printf("\n1. Create Queue\n2. EnQueue\n3. DeQueue");
        printf("\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if(Q != NULL)
                {
                    printf("Queue already exists !");
                    break;
                }
                printf("Enter Size: ");
                scanf("%d",&size);
                Q = CreateQueue(size);
                printf("Queue Successfully Created!");
                break;
            case 2:
                if (Q == NULL)
                {
                    printf("Create a Queue first !");
                    break;
                }
                printf("Enter Value: ");
                scanf("%d", &data);
                EnQue(Q, data);
                break;
            case 3:
                if(Q == NULL)
                {
                    printf("Create a Queue first !");
                    break;
                }
                data = DeQue(Q);
                if(data == -1)
                {
                    printf("Queue is Empty !");
                }
                else
                {
                   printf("Removed data = %d", data); 
                }
                break;
            case 4:
                printf("exititng...");
                exit(0);
            default:
                break;
        }
    }
}