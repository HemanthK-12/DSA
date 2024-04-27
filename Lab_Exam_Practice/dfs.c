#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;
Node*top=NULL;

void push(int x)
{
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

void pop()
{
    Node*temp=top;
    if(top==NULL)
        return;
    top=top->next;
    free(temp);
}

int peek()
{
    if (top != NULL)
        return top->data;
    return -1;    
}

void display()
{
    Node*temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    free(temp);
}

void dfs(int** graph,int start,int vertices)
{
    int* visited=(int*)calloc(vertices,sizeof(int));
    push(start);
    while(top!=NULL)
    {
        int current=peek();
        pop();
        if(!visited[current])
        {
            printf("%d\n",current);
            visited[current]=1;
        }
        for(int i=0;i<vertices;i++)
            if(graph[current][i]==1 && !visited[i])
                push(i);
    }
    free(visited);
}

int main()
{
    int edges,vertices;
    scanf("%d %d",&edges,&vertices);

    int**graph=(int**)malloc(vertices*sizeof(int*));
    for(int i=0;i<vertices;i++)
        graph[i]=(int*)calloc(vertices,sizeof(int));
    for(int i=0;i<edges;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    dfs(graph,0,vertices);

    for(int i=0;i<vertices;i++)
        free(graph[i]);
    free(graph);
    return 0;
}
