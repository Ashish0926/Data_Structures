#include <stdio.h>
#include <stdlib.h>

struct DynArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct DynArrayStack *CreateStack()
{
    struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));
    if (!S)
    {
        return NULL;
    }
    S->top = -1;
    S->capacity = 1;
    S->array = malloc(sizeof(int) * S->capacity);
    if (!S->array)
    {
        return NULL;
    }
    return S;
}
int isEmptyStack(struct DynArrayStack *S)
{
    return (S->top == -1);
}
int isFullStack(struct DynArrayStack *S)
{
    return (S->top = S->capacity - 1);
}
void DoubleStack(struct DynArrayStack *S)
{
    S->capacity = S->capacity * 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}
void Push(struct DynArrayStack *S, int data)
{
    if (isFullStack(S))
    {
        DoubleStack(S);
    }
    S->top++;
    S->array[S->top] = data;
}
int Top(struct DynArrayStack *S)
{
    if (isEmptyStack(S))
    {
        return __INT16_MAX__;
    }
    return S->array[S->top];
}
int Pop(struct DynArrayStack *S)
{
    if (isEmptyStack(S))
    {
        return __INT16_MAX__;
    }
    return S->array[S->top--];
}
void DeleteStack(struct DynArrayStack *S) 
{
    if(S)
    {
        if (!S->array)
        {
            free(S->array);
        }
        free(S);
    }
}
void main()
{
    struct DynArrayStack *stack;
    stack = CreateStack();
    int choice, item, pop;
    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &item);
            Push(stack, item);
            break;
        case 2:
            pop = Pop(stack);
            printf("Popped item : %d", pop);
            break;
        case 3:
            exit(0);
        }
    }
}