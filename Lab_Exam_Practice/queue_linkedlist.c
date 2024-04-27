#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node *front=NULL;
Node*rear=NULL;

void enqueue(int x)
{
    Node* newnode=malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void display()
{
    Node *temp;
    if(front==NULL && rear==NULL)
        printf("Queue empty");
    else
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
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
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        enqueue(a);
    }
    display();
}