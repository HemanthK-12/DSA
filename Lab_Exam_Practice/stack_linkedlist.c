#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;
Node *top = 0;
void push(int x)
{
    Node* newnode=malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void display()
{
    Node* temp;
    temp=top;
    if(top==NULL)
        printf("Stack is empty");
    else
    {   
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;//goes to next element
        }
    }
}
void peek()
{
    if(top==NULL)
        printf("Stack is empty");
    else
        printf("Top data = %d",top->data);
}
void pop()
{
    Node* temp;
    temp=top;
    if(top==NULL)
        printf("Stack is empty");
    else
        {
            printf("%d",top->data);
            top=top->next;
            free(temp);
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        push(a);
    }
    display();
}