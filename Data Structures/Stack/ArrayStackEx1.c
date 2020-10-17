#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayStack
{
    int capacity;
    int top;
    int *arr;
}ArrayStack;

ArrayStack *createStack(int capacity);
int isStackFull(ArrayStack *S);
int isStackEmpty(ArrayStack *S);
void Push(ArrayStack *S, int data);
int Pop(ArrayStack *S);
int Top(ArrayStack *S);

ArrayStack *createStack(int capacity)
{
    ArrayStack *S = malloc(sizeof(ArrayStack));
    if(S == NULL)
    {
        printf("Memeory Error");
    }
    S->top = -1;
    S->capacity = capacity;
    S->arr = (int *)malloc(sizeof(int)*S->capacity);
    return S;
}
int isStackFull(ArrayStack *S)
{
    return (S->top == S->capacity - 1);
}
int isStackEmpty(ArrayStack *S)
{
    return(S->top == -1);
}

void Push(ArrayStack *S, int data)
{
    if(!isStackFull(S))
    {
        S->top++;
        S->arr[S->top] = data;
    }
    else
    {
        printf("Stack is Full");
    }
}

int Pop(ArrayStack *S)
{
    if(!isStackEmpty(S))
    {
        return (S->arr[S->top--]);
    }
    else
    {
        printf("Stack is Empty");
        return -1;
    }
}

int Top(ArrayStack *S)
{
    return S->arr[S->top];
}

void main()
{
    ArrayStack *stack;
    stack = createStack(4);
    int choice, data;
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print top");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d",&data);
                Push(stack,data);
                break;
            case 2:
                data = Pop(stack);
                printf("\nPopped data : %d",data);
                break;
            case 3:
                data = Top(stack);
                printf("Element at Top: %d",data);
                break;
            case 4:
                exit(0);
        }
    }
}