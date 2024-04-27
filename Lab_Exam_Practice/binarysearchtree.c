#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}Node;

Node* createTree(int x)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
bool insertTree(Node**rootptr,int data)
{
    Node* root=*rootptr;
    if(root==NULL)
        {
            (*rootptr)=createTree(data);
            return true;
        }
    if(data==root->data)
        return false;
    if(data<root->data)
        return insertTree(&(root->left),data);
    else
        return insertTree(&(root->right),data);
}
bool findNode(Node* root,int data)
{
    if(root==NULL)
        return false;
    if(root->data==data)
        return true;
    if(data<root->data)
        return findNode(root->left,data);
    else
        return findNode(root->right,data);
}
int main()
{
    Node*root=NULL;
    insertTree(&root,15);
    insertTree(&root,4);
    insertTree(&root,6);
    insertTree(&root,7);
    insertTree(&root,11);
    insertTree(&root,3);
    insertTree(&root,2);
    insertTree(&root,13);
}