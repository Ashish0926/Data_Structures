#include<stdio.h>
#include<stdlib.h>

typedef struct Heap
{
    int *arr;
    int count;
    int capacity;
} heap;

heap *createHeap(int capacity)
{
    heap *h = (heap *)malloc(sizeof(heap));
    if(h == NULL)
    {
        printf("memory error");
        return;
    }
    h->count = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(sizeof(int) * h->capacity);
    if(h->arr = NULL)
    {
        printf("memory error");
        return;
    }
    return h;
}

int insert(heap *h, int data)
{
    int i;
    if(h->count == h->capacity){
        resizeHeap(h);
    }
    h->count = h->count + 1;
    i = h->count - 1;
    while(i>=0 && data > h->arr[(i-1)/2])
    {
        
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, choice, data;   
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &n);
        switch (choice) {
        case 1:
        }
    }
    return 0;
}