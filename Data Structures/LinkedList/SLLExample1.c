#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}node;

node *createList(node *head, int num);
node *insertNodeAtTail(node *head, int data);
node *insertNodeAtHead(node *head, int data);
int DeleteNodeAtTail(node *head);
int DeleteNodeAtHead(node *head);
void DeleteNode(node *head, int pos);
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
node *insertNodeAtTail(node *head, int data)
{
    node* newNode, *temp;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        return head;
    }
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}
node *insertNodeAtHead(node *head, int data)
{
    node *newNode = malloc(sizeof(newNode));
    newNode->data = data;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
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
void DeleteNode(node *head, int pos)
{
    node *temp, *temp1;
    int cnt = 1;
    if(head == NULL)
    {
        return;
    }
    if(pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    temp = head;
    while(cnt < pos-1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp != NULL)
    {
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
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
    head = head->next;
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
        printf("\n1. Create List \n2. Insert Node at Tail");
        printf("\n3. Insert Node at Head \n4. Traverse List & Print");
        printf("\n5. Delete Node at Tail\n6. Delete Node at Head");
        printf("\n7. List Length \n8. Reverse List & Print");
        printf("\n9. Exit \nEnter your choice: ");   
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter list size: ");
                scanf("%d",&size);
                head = createList(head, size);
                break;
            case 2:
                printf("Enter Node data: ");
                scanf("%d",&data);
                head = insertNodeAtTail(head, data);
                break;
            case 3:
                printf("Enter Node data: ");
                scanf("%d",&data);
                head = insertNodeAtHead(head, data);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                data = DeleteNodeAtTail(head);
                printf("Deleted %d",data);
                break;
            case 6:
                data = DeleteNodeAtHead(head);
                printf("Deleted %d",data);
                break;
            case 7:
                data = ListLength(head);
                printf("List Length : %d",data);
                break;
            case 8:
                head = reverseList(head);
                traverse(head);
                break;
            case 9:
                printf("exiting ...");
                exit(0);
            default:
                printf("invalid input");
        }
    }
    return 0;
}