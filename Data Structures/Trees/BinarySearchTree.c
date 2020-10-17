#include <stdio.h>
#include <stdlib.h>

//tree node
struct binTreeNode
{
    int data;
    struct binTreeNode *lchild, *rchild;
};

// A complete C program to create a binary search tree :
struct binTreeNode *insert(struct binTreeNode *p, int val)
{
    struct binTreeNode *temp1, *temp2;
    if (p == NULL)
    {
        // insert new node as root node
        p = (struct binTreeNode *)malloc(sizeof(struct binTreeNode));
        if (p == NULL)
        {
            printf("Memory Error");
            exit(0);
        }
        p->data = val;
        p->lchild = p->rchild = NULL;
    }
    else
    {
        temp1 = p;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            if (temp1->data > val)
                temp1->lchild;
            else
                temp1->rchild;
        }
        if (temp2->data > val)
        {
            temp2->lchild = (struct binTreeNode *)malloc(sizeof(struct binTreeNode));
            if (temp2->lchild == NULL)
            {
                printf("Memory Error");
                exit(0);
            }
            temp2 = temp2->lchild;
            temp2->data = val;
            temp2->lchild = temp2->rchild = NULL;
        }
        else
        {
            temp2->rchild = (struct binTreeNode *)malloc(sizeof(struct binTreeNode));
            if (temp2->rchild == NULL)
            {
                printf("Memory Error");
                exit(0);
            }
            temp2 = temp2->rchild;
            temp2->data = val;
            temp2->lchild = temp2->rchild = NULL;
        }
    }
    return (p);
}

// Function to traverse the binary tree and print the data in Inorder (LDR)
void Inorder(struct binTreeNode *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        printf("%d", p->data);
        Inorder(p->rchild);
    }
}

void main()
{
    struct binTreeNode *root = NULL;
    int val, n;
    printf("\nEnter the number of nodes you want in the tree: ");
    scanf("%d", &n);
    while (n--)
    {
        printf("Enter Value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }
    Inorder(root);
}