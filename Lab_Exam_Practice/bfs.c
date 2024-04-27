#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;

Node*front=NULL;
Node*rear=NULL;

void enqueue(int x)
{
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->next=NULL;
    if(front==NULL && rear==NULL)
        front=rear=newNode;
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue()
{
    if(front==NULL)
        return;
    Node*temp=front;
    if(front == rear)
        front=rear=NULL;
    else
        front=front->next;
    free(temp);
}
int frontElement()
{
    if(front!=NULL)
        return front->data;
    else
        return -1;

}
void display()
{
    Node*temp=front;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    free(temp);
}
void bfs(int** graph,int start,int vertices)
{
    int* visited=(int*)calloc(vertices,sizeof(int));
    printf("%d\n",start);
    visited[start]=1;
    enqueue(start);

    while(front!=NULL)
    {
        int current=frontElement();
        dequeue();
        for(int i=0;i<vertices;i++)
        {
            if(graph[current][i]==1 && !visited[i])
            {
                printf("%d\n",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    free(visited);
}
int main()
{
    int edges,vertices;
    scanf("%d %d", &edges, &vertices);

    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++)
        graph[i] = (int*)calloc(vertices, sizeof(int));
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        graph[v][u] = 1;
    }
    bfs(graph, 0, vertices);

    for (int i = 0; i < vertices; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
