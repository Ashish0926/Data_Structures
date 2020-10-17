#include <stdio.h>
#include <stdlib.h>

struct DLLNode
{
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};

void DLLInsert(struct DLLNode **head, int data, int position)
{
    int cnt = 1;
    struct DLLNode *newNode, *temp;
    newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    temp = *head;
    while ((cnt < position - 1) && (temp->next != NULL))
    {
        temp = temp->next;
        cnt++;
    }
    if (cnt != position-1)
    {
        printf("invalid position");
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return;
}
void DLLDelete(struct DLLNode **head, int position)
{
    struct DLLNode *temp1;
    int cnt = 1;
    if(*head == NULL)
    {
        printf("List is Empty");
        return;
    }
    temp1 = *head;
    if(position == 1)
    {
        temp1->prev = NULL;
        (*head) = (*head)->next;
    }
    free(temp1);
}
