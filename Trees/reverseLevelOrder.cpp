#include <bits/stdc++.h>
using namespace std;

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
}tree;

void BSTinsert(tree **root, int data) {
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

void levelOrder(tree *root){
    if(root == NULL){
        cout << "Error: tree doesn't exist!" << endl;
        return;
    }
    tree *temp;
    queue<tree *> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->data <<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void reverseLevelOrder(tree *root){
    if(root == NULL){
        cout << "Error: tree doesn't exist!" << endl;
        return;
    }
    tree *temp;
    stack<tree *> s;
    queue<tree *> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        s.push(temp);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    while (!s.empty()){
        cout << s.top()->data <<" ";
        s.pop();
    }
}

void deleteBinaryTree(tree *root){
    if(root == NULL){
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    free(root);
}

int main() {
    tree *root = NULL;
    int choice, data, cnt = 0;
    while(1) {
        printf("\n1. Insert\n2. Level Order Traversal\n3. Reverse Level Order Traversal");
        printf("\n4. Delete Binary Tree\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                BSTinsert(&root, data);
                break;
            case 2:
                levelOrder(root);
                printf("\n");
                break;
            case 3:
                reverseLevelOrder(root);
                printf("\n");
                break;
            case 4:
                deleteBinaryTree(root);
                root = NULL;
                printf("\n");
                break;
            case 5:
                printf("exiting...");
                exit(0);
                break;
            default :
                break;
        }
    }
    return 0;
}