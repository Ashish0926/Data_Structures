#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}node;

node *createList(node *head, int num);
int DeleteNodeAtTail(node *head);
int DeleteNodeAtHead(node *head);
void traverse(node *head);
int ListLength(node *head);
node *reverseList(node *head);

node *createList(node *head, int num)
{
    node *temp, *newNode;
    int data;
    if(head != NULL)
    {
        printf("Node already exists");
        return head;
    }
    for(int i=0; i<num; i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void traverse(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf(" --> %d",temp->data);
        temp = temp->next;
    }
    printf("\n");   
}

int DeleteNodeAtHead(node *head)
{
    node *temp;
    int data;
    if(head == NULL)
    {
        return -1;
    }
    data = head->data;
    temp = head;
    head = temp->next;
    free(temp);
    return data;
}

int DeleteNodeAtTail(node *head)
{
    node *temp1, *temp2;
    int data;
    if(head == NULL)
    {
        return -1;
    }
    temp1 = head;
    while(temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    data = temp1->data;
    temp2->next = NULL;
    free(temp1);
    return data;
}

int ListLength(node *head)
{
    node *temp;
    int cnt = 1;
    if(head == NULL)
    {
        return 0;
    }
    temp = head;
    while(temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

node *reverseList(node *head)
{
    node *current, *nxt, *prev;
    current = head;
    nxt = NULL;
    prev = NULL;
    if(head == NULL)
    {
        return head;
    }
    while(current != NULL)
    {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    head = prev;
    return head;
}

int main()
{
    node *head = NULL;
    int choice, size, data, pos;
    while(1)
    {
        printf("\n1. Create List ");
        printf("\n2. Traverse List & Print");
        printf("\n3. Delete Node at Tail \n4. List Length");
        printf("\n5. Delete Node at Head \n6. Reverse List & Print");
        printf("\n7. Exit \nEnter your choice: ");   
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter list size: ");
                scanf("%d",&size);
                head = createList(head, size);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                data = DeleteNodeAtTail(head);
                printf("Deleted %d",data);
                break;
            case 5:
                data = DeleteNodeAtHead(head);
                printf("Deleted %d",data);
                break;
            case 4:
                size = ListLength(head);
                printf("List Length : %d",size);
                break;
            case 6:
                head = reverseList(head);
                traverse(head);
                break;
            case 7:
                printf("exiting ...");
                exit(0);
            default:
                printf("invalid input");
        }
    }
    return 0;
}