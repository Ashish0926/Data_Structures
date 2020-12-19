#include <bits/stdc++.h>
using namespace std;

typedef struct Tree{
    int data;
    struct Tree *left, *right;
}tree;

tree *newNode(int data){
    tree *newNode = new tree;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

tree *insertData(tree *root, int data, queue<tree *> &q){
    tree *n = newNode(data);
    if(root == NULL){
        root = n;
    }
    else if(q.front()->left == NULL){
        q.front()->left = n;
    }
    else{
        q.front()->right = n;
        q.pop();
    }
    q.push(n);
    return root;
}

tree *createTree(int arr[], int n){
    tree *root = NULL;
    queue<tree *>q;
    for(int i=0; i<n; i++){
        root = insertData(root, arr[i], q);
    }
    return root;
}

void inorderTraversal(tree *root){ 
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data <<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(tree *root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(tree *root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data <<" ";
}

void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    int n;
    printf("|| PROGRAM TO CREATE AND TRAVERSE A BINARY TREE ||\nEnter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter node values : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    n = sizeof(arr)/sizeof(int);
    tree *root = createTree(arr, n);
    printf("PreOrder Traveral --> ");
    preorderTraversal(root);
    printf("\n");
    printf("InOrder Traveral --> ");
    inorderTraversal(root);
    printf("\n");
    printf("PostOrder Traveral --> ");
    postorderTraversal(root);
    return 0;
}