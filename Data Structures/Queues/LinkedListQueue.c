#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} LinkedList;

typedef struct Queue
{
    LinkedList *front;
    LinkedList *rear;
} Queue;

Queue *CreateQueue()
{
    Queue *Q = malloc(sizeof(Queue));
    if (!Q)
    {
        printf("Memory Error");
    }
    Q->front = Q->rear = NULL;
    return Q;
}

int isEmpty(Queue *Q)
{
    return (Q->front == NULL);
}

void EnQueue(Queue *Q, int data)
{
    LinkedList *newNode = malloc(sizeof(LinkedList));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    if(Q->rear == NULL)
    {
        Q->rear = newNode;
        newNode->next = NULL;
    }
    else
    {
        Q->rear->next = newNode;
        Q->rear = newNode;
        newNode->next = NULL;
    }
    if(Q->front == NULL)
    {
        Q->front = Q->rear;
    }
}

int DeQueue(Queue *Q)
{
    LinkedList *temp;
    int data;
    if (isEmpty(Q))
    { 
        return -1;
    }
    data = Q->front->data;
    temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    return data;
}

void main()
{
    Queue *Q = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Create Queue\n2. EnQueue\n3. DeQueue");
        printf("\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                Q = CreateQueue();
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
                EnQueue(Q, data);
                break;
            case 3:
                data = DeQueue(Q);
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