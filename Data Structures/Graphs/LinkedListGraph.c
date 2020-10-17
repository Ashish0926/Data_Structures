#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode
{
    int VertexNum;
    struct LinkedListNode *next;
} node;

typedef struct Graph
{
    int V;
    int E;
    node *Adj;
} Graph;

Graph *CreateGraph()
{
    Graph *G = malloc(sizeof(Graph));
    node *temp;
    int i, x, y;
    if (!G)
    {
        printf("Memory Error");
    }
    printf("Enter Number of Vertex : ");
    scanf("%d", &G->V);
    printf("Enter Number of Edges : ");
    scanf("%d", &G->E);
    G->Adj = malloc(G->V * sizeof(node));
    for (i = 0; i < G->V; i++)
    {
        G->Adj->VertexNum = i;
        G->Adj->next = G->Adj;
        G->Adj = G->Adj + 1;
    }
    for(i = 0; i< G->E; i++)
    {
        scanf("Reading Edge: %d %d", &x, &y);
        temp = (node *)malloc(sizeof(node));
        temp->VertexNum = y;
        temp->next = G->Adj[x];
    }

    return G;
}
