#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *head)
{
    struct ListNode *current = head;
    int cnt = 0;
    while (current != NULL)
    {
        cnt++;
        current = current->next;
    }
    return cnt;
}

void insertLinkedList(struct ListNode **head, int position, int data)
{
    struct ListNode *p, *q, *newNode = malloc(sizeof(struct ListNode));
    int cnt = 1;
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    p = *head;
    if (position == 1)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        while ((cnt < position) && (p != NULL))
        {
            q = p;
            p = p->next;
            cnt++;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteNodeFromLL(struct ListNode **head, int position)
{
    struct ListNode *p, *q;
    int cnt = 1;
    if (*head == NULL)
    {
        printf("Memory Error");
        return;
    }
    p = *head;
    if (position == 1)
    {
        *head = (*head)->next;
        free(p);
        return;
    }
    else
    {
        while ((cnt < position) && (p != NULL))
        {
            q = p;
            p = p->next;
            cnt++;
        }
        if (p == NULL)
        {
            printf("Node does not exist");
            return;
        }
        else
        {
            q->next = p->next;
            free(p);
        }
    }
}
void DeleteLL(struct ListNode **head)
{
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while (iterator)
    {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}

int main()
{
    struct ListNode *head;
}