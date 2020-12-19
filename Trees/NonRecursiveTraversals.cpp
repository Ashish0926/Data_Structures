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

void preOrder(tree *root){
    if(root == NULL){
        return;
    }
    tree *temp;
    stack<tree *>s;
    s.push(root);
    while(!s.empty()){
        temp = s.top();
        cout << temp->data <<" ";
        s.pop();
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void inOrder(tree *root){
    stack<tree *> s; 
    tree *temp = root; 
    while (temp != NULL || !s.empty()) 
    {
        while (temp !=  NULL) 
        { 
            s.push(temp); 
            temp = temp->left; 
        }
        temp = s.top(); 
        s.pop(); 
        cout << temp->data << " ";
        temp = temp->right; 
    }
}

void postOrder(tree *root){
    tree *temp = root, *prev = NULL;
    stack<tree *>s;
    do{
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        while(temp == NULL && !s.empty()){
            temp = s.top();
            if(temp->right == NULL || temp->right == prev){
                cout << temp->data <<" ";
                s.pop();
                prev = temp;
                temp = NULL;
            }
            else{
                temp = temp->right;
            }
        }
    }while(!s.empty());
}

void levelOrder(tree *root){
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

int main() {
    tree *root = NULL;
    int choice, data;
    while(1) {
        printf("\n1. Insert\n2. PreOrder Traverse\n3. InOder Traverse");
        printf("\n4. PostOrder Traverse\n5. Level Order Traverse");
        printf("\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                BSTinsert(&root, data);
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
                levelOrder(root);
                printf("\n");
                break;
            case 6:
                printf("exiting...");
                exit(0);
                break;
            default :
                break;
        }
    }
    return 0;
}