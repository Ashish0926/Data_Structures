#include<stdio.h>
#include<stdlib.h>

typedef struct CircularLinkedListNode
{
    int data;
    struct CircularLinkedListNode *next;
}CLLNode;

CLLNode *head = NULL, *newNode, *temp;

void insertAtEnd(int data)
{
    newNode = malloc(sizeof(CLLNode));
    temp = head;
    newNode->data = data;
    newNode->next  = newNode;
    if((head) == NULL)
    {
        (head) = newNode;
        return;
    }
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = (head);
}
void insertAtBeg(int data)
{
    newNode = malloc(sizeof(CLLNode));
    temp = head;
    newNode->data = data;
    newNode->next  = newNode;
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void DeleteEnd()
{
    if(head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            newNode = temp;
            temp = temp->next;
        }
        newNode->next = temp->next;
        free(temp);
    }
}
void DeleteAtBeg()
{
    if(head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        newNode = temp->next;
        temp->next = newNode->next;
        head = head->next;
        free(newNode);
    }
}

void TraversePrintCLL()
{
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while(temp->next != (head))
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main()
{
    int choice, data;
    while(1)
    {
        printf("1. Insert at End\n2. Insert at Beginning\n");
        printf("3. Delete at End\n4. Delete at Beginning\n");
        printf("5. Traverse & Print\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                insertAtBeg(data);
                break;
            case 3:
                DeleteEnd();
                break;
            case 4:
                DeleteAtBeg();
                break;
            case 5:
                TraversePrintCLL();
                break;
            case 6:
                printf("exiting...");
                exit(0);
            default:
                break;
        }
    }
}
