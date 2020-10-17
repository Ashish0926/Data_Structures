#include <stdio.h>
#include <stdlib.h>

typedef struct CLLNode
{
    int data;
    struct CLLNode *next;
}CLLNode;

CLLNode *head, *x, *y;

int CircularListLength(CLLNode *head)
{
    struct CLLNode *current = head;
    int cnt = 1;
    if (head == NULL)
    {
        return 0;
    }
    while (current->next != head)
    {
        cnt++;
        current = current->next;
    }
    return cnt;
}
void printCLL(CLLNode *head)
{ 
    CLLNode *temp = head; 
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

void insertAtEnd(int data)
{
    x = (CLLNode *)malloc(sizeof(CLLNode));
    x->data = data;
    if(head == NULL)
    {
        x->next = x;
        head = x;
    }
    else
    {
        temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        free(temp);
    }

}

int main()
{
    CLLNode *head = NULL;
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
            insertAtEnd(&head, data);
            break;
        case 2:
            printCLL(head);
            break;
        case 3:
            printf("exiting...");
            exit(0);
        default:
            break;
        }
    }
}