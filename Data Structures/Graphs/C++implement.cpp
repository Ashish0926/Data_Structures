#include<iostream>
using namespace std;

struct adjNode
{
    int val;
    adjNode* next;
};

struct graphEdge
{
    int src, dest; //src = source, dest = destination 
};

class Graph
{
    adjNode *getAdjListNode(int dest, adjNode *head)
    {
        adjNode *newNode = new adjNode;
        newNode->val = dest;
        newNode->next = head;
        return newNode;
    }
    int N; //number of nodes in the graph
public:

    adjNode **head;
    Graph(graphEdge edges[], int n, int N)
    {
        head = new adjNode *[N]();
        this->N = N;
        for(int i = 0; i < N; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            adjNode *newNode = getAdjListNode(dest, head[src]);
            head[src] = newNode;
        }
    }
    ~Graph()
    {
        for(int i = 0; i < N; i++)
        {
            delete[] head[i];
        }
        delete[] head;
    }
};

void printList(adjNode *ptr)
{
    while(ptr != nullptr)
    {
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    graphEdge edges[] = 
    {
        {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    };
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph graph(edges, n, N);
    
    for(int i=0; i < N; i++)
    {
        cout << i << " --";
        printList(graph.head[i]);
    }
    return 0;
}