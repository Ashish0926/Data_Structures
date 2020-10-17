#include<stdio.h>
#include<stdlib.h>

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack *CreateStack(int cap)
{
    struct ArrayStack *Stack;
    Stack = malloc(sizeof(struct ArrayStack));
    Stack->capacity = cap;
    Stack->top = -1;
    Stack->array = malloc(sizeof(int)*Stack->capacity);
    return(Stack);
};
int isFull(struct ArrayStack *Stack)
{
    if(Stack->top == Stack->capacity-1)
        return(1);
    else
        return(0);
}
int isEmpty(struct ArrayStack *Stack)
{
    if(Stack->top == -1)
        return(1);
    else
        return(0);
}
void push(struct ArrayStack *Stack, int item)
{
    if(!isFull(Stack))
    {
        Stack->top++;
        Stack->array[Stack->top] = item;
    }
    else
    {
        printf("Stackoverflow\n");
    }
}
void pop(struct ArrayStack *Stack)
{
    int item;
    if(!isEmpty(Stack))
    {
        item = Stack->array[Stack->top];
        Stack->top--;
        printf("Popped item: %d\n",item);
    }
    else
    {
        printf("Stack is empty\n");
    }
}
void main()
{
    struct ArrayStack *stack;
    stack = CreateStack(4);
    int choice, item;
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d",&item);
                push(stack,item);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                exit(0);
        }
    }
}