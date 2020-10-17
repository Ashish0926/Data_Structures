#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
void push(struct Node **head_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node *temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
  
    if (*head_ref != NULL) 
    { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } 
    else
        *head_ref =  ptr1;
} 
  
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
} 

int main()
{
    struct Node *head = NULL;
    int choice, data;
    while(1)
    {
        printf("1. Insert at end\n2. Print List\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("exiting...");
            exit(0);
        default:
            break;
        }
    }
}