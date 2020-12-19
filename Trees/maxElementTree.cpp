#include <bits/stdc++.h>
using namespace std;

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
    int max = INT_MIN;
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

int searchData(tree *root, int data){
    tree *temp;
    queue<tree *> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == data){
            return 1;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return 0;
}

int sizeofTree(tree *root){
    if(root == NULL){
        return 0;
    }else{
        return(sizeofTree(root->left) + 1 + sizeofTree(root->right));
    }
}

int main() {
    tree *root = NULL;
    int choice, data, cnt = 0;
    while(1) {
        printf("\n1. Insert\n2. Level Order Traversal\n3. Find Max Element\n4. Search Tree");
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
                data = searchData(root, data);
                if(data == 1){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
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