#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    int size;
}Queue;

Queue *create_queue()
{
    Queue *queue=malloc(sizeof(Queue));

    queue->head=NULL;
    queue->tail=NULL;
    queue->size=0;

    return queue;
}
int peek(Queue *queue,bool *status)
{
    if(is_empty(queue))
    {
        *status=false;
        return NULL;
    }
    *status=true;
    return queue->head->data;
}
void enqueue(Queue *queue,int value)
{
    Node *newNode=malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(is_empty(queue))
    {
        queue->head=newNode;
        queue->tail=newNode;
    }
    else
    {
        queue->tail->next=newNode;
        queue->tail=newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue,bool *status)
{
    if(is_empty(queue))
    {
        *status=false;
        return 0;
    }
    *status=true;

    int value=queue->head->data;
    Node *oldHead=queue->head;
    if(size(queue)==1)
    {
        queue->head=NULL;
        queue->tail=NULL;
    }
    else
        queue->head=queue->head->next;
    free(oldHead);
    queue->size--;
    return value;
}
void destroy_queue(Queue *queue)
{
    Node *currentNode=queue->head;

    while(currentNode!=NULL)
    {
        Node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp);
    }
    free(queue);
}

int main()
{
    Queue *queue=create_queue();
    if(is_empty(queue))
        printf("Empty Queue");
        enqueue(queue,5);
        enqueue(queue,8);
        enqueue(queue,7);
        if(is_empty(queue))
            printf("Still Empty");
        else 
        printf("Size=%d",size(queue));
        bool status=false;
        int value=0;
        value=peek(queue,&status);
        if(status==true)
            printf("Peek=%d",value);
        
}