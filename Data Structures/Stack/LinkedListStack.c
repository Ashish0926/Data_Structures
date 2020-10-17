#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedListStack  
{  
    int data;  
    struct LinkedListStack* next;  
}StackLL;  
  
void Push(int data);
int isEmpty();
int Top();
void Pop();

StackLL* top;  

void Push(int data)  
{   
    StackLL* temp = malloc(sizeof(StackLL));  
    if (!temp) 
    {  
        printf("Memory error");
        exit(1);  
    }    
    temp->data = data;    
    temp->next = top;  
    top = temp;  
}  

int isEmpty()  
{  
    return top == NULL;  
} 

int Top()  
{
    if (!isEmpty())  
        return top->data;  
    else
        exit(1);  
}  

void Pop()  
{  
    StackLL* temp; 
    if (top == NULL)  
    {  
        printf("stack underflow"); 
        exit(1);  
    }  
    else
    {    
        temp = top; 
        top = top->next;  
        temp->next = NULL;
        printf("Poppped data: %d",temp->data);
        free(temp);  
    }  
}
 
void main()
{
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
                Push(data);
                break;
            case 2:
                Pop();
                break;
            case 3:
                data = Top();
                printf("Element at Top: %d",data);
                break;
            case 4:
                exit(0);
        }
    }
} 