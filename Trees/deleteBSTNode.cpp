#include <bits/stdc++.h>
using namespace std;

typedef struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode *left, *right;
}tree;

tree *inorderSuccessor(tree *root);

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

int findMax(tree *root){
    tree *temp; 
    int max;
    queue<tree *> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data > max){
            max = temp->data;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return max;
}

tree *delBSTNode(tree **root, int data) {
    tree *par, *temp = *root;
    while(temp != NULL || data != temp->data) {
        if(data < temp->data) {
            par = temp;
            temp = temp->left;
        }
        else if(data > temp->data) {
            par = temp;
            temp = temp->right;
        }
    }
    if(temp == NULL) {
        printf("node does not exist.");
        return *root;
    }
    if(temp->left == NULL && temp->right == NULL) {
        if(par->left) {
            par->right = NULL;
        }
        else {
            par->left = NULL;
        }
        free(temp);
    }
    else if(temp->left == NULL || temp->right == NULL) {
        if(par->left) {
            par->left = (temp->left) ? temp->left : temp->right;
        }
        else {
            par->right = (temp->right) ? temp->right : temp->left;
        }
    }
    else {
        temp->data = inorderSuccessor(temp)->data;
        delBSTNode(root, inorderSuccessor(temp)->data);
    }
    return *root;
}

tree *inorderSuccessor(tree *root) {
    tree *temp = root->right;
    int min = temp->data;
    if(temp == NULL){
        return temp;
    }
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

int main() {
    tree *root = NULL;
    tree *temp;
    int choice, data, cnt = 0;
    while(1) {
        printf("\n1. Insert\n2. Level Order Traversal\n3. Find Max Element\n4. Delete Tree Node");
        printf("\n5. Size of Tree\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            cnt+=1;
        }
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert(&root, data);
                break;
            case 2:
                levelOrder(root);
                printf("\n");
                break;
            case 3:
                data = findMax(root);
                printf("max element: %d",data);
                printf("\n");
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d",&data);
                root = delBSTNode(&root, data);
                break;
            case 5:
                data = cnt;
                printf("%d\n",data);
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