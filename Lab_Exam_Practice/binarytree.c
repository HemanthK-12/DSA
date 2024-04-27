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
    Node* tree=(Node*)malloc(sizeof(int));
    tree->data=x;
    tree->left=NULL;
    tree->right=NULL;
    return tree;
}

int main()
{
    Node* one=createTree(5);
    Node*two=createTree(2);
    Node*three=createTree(7);

    one->left=two;
    one->right=three;
    return 0;
}

Node* insertlevelorder(int arr[],Node* root,int i,int n)
{
    if(i<n)
    {
        Node*temp=createTree(arr[i]);
        root=temp;
        root->left=insertlevelorder(arr,root->left,2*i+1,n);
        root->right=insertlevelorder(arr,root->right,2*i+2,n);      
    }
    return root;
}

Node* buildtree(int a[],int n)
{
    if(n<0)
        return NULL;
    Node** newNode=(Node**)malloc(n*sizeof(Node));
    for(int i=0;i<n;i++)
        newNode[i]=(a[i]==-1)?NULL:createTree(a[i]);
    Node* root=newNode[0];
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(newNode[i]==NULL)
            count++;
        if(newNode[i])
        {
            int left=2*i+1-2*count;
            int right=2*i+2-2*count;
            if(left<n)
                newNode[i]->left=newNode[left];
            if(right<n)
                newNode[i]->right=newNode[right];
        }
    }
    free(newNode);
    return root;
}

bool isIdentical(Node* root1,Node*root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    if(root1->data !=root2->data)
        return 0;
    return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}
bool isSubTree(Node* root1,Node*root2)
{
    if(root1==NULL)
        return 0;
    if(root2==NULL)
        return 1;
    if(isIdentical(roo1,root2))
        return 1;
    return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
}
