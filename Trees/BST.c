#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode *left, *right;
}tree;

void insert(tree **root, int data) {
    tree *par, *newNode, *temp = *root;
    while(temp != NULL){
        if(temp->data == data){
            printf("Error: cannot store dublicate elements.\n");
            return;
        }
        else if(temp->data < data){
            par = temp;
            temp = temp->right;
        }
        else{
            par = temp;
            temp = temp->left;
        }
    }
    newNode = (tree *)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if(temp == *root){
        *root = newNode;
        return;
    }
    if(par->data < data){
        par->right = newNode;
    }
    else if(par->data > data){
        par->left = newNode;
    }
}

void preOrder(tree *root) {
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tree *root) {
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void postOrder(tree *root) {
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

// recursive search
int SearchBST(tree *root, int key){
    if(root == NULL){
        return 0;
    }
    if(key == root->data){
        return 1;
    }
    int a = SearchBST(root->left, key);
    int b = SearchBST(root->right, key);
    if(a || b){
        return 1;
    }
    else{
        return 0;
    }
}

// non - recursive search
int search(tree *root, int key){
    while(root != NULL && root->data != key){
        if(key > root->data){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    if(root == NULL){
        return 0;
    }
    return 1;
}

void delLeafNode(tree *root, int key){
    tree *temp = root, *par;
    while(temp != NULL && temp->data != key){
        if(key > temp->data){
            par = temp;
            temp = temp->right;
        }else{
            par = temp;
            temp = temp->left;
        }
    }
    if(temp == NULL){
        printf("does not exist.");
    }
    if(par->data < temp->data){
        par->right = NULL;
    }else
    {
        par->left = NULL;
    }
    free(temp);
}

int main() {
    tree *root = NULL;
    int choice, data;
    while(1) {
        printf("\n1. Insert\n2. PreOrder Traverse\n3. InOrder Traversal\n4. PostOrder Traversal\n5. Search\n6. Delete leaf Node\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert(&root, data);
                break;
            case 2:
                preOrder(root);
                printf("\n");
                break;
            case 3:
                inOrder(root);
                printf("\n");
                break;
            case 4:
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d",&data);
                if(search(root, data)){
                    printf("Element is present in tree!");
                }else{
                    printf("Element is not present in tree!");
                }
                printf("\n");
                break;
            case 6:
                printf("Enter data: ");
                scanf("%d",&data);
                delLeafNode(root, data);
                break;
            case 7:
                printf("exiting...");
                exit(0);
            default :
                break;
        }
    }
    return 0;
}