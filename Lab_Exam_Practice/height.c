#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node*left;
    struct node* right;
}Node;

Node* createNode(int x)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node* buildTree(int a[],int n)
{
    if(n<0)
        return NULL;
    Node** nodelist=(Node**)malloc(n*sizeof(Node));
    for(int i=0;i<n;i++)
        nodelist[i]=(a[i]==-1)?NULL:createNode(a[i]);
    Node* root=nodelist[0];
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(nodelist[i]==NULL)
            count++;
        if(nodelist[i])
        {
            int leftI=2*i+1-2*count;
            int rightI=2*i+2-2*count;
            if(leftI<n)
                nodelist[i]->left=nodelist[leftI];
            if(rightI<n)
                nodelist[i]->right=nodelist[rightI];
        }
    }
    free(nodelist);
    return root;
}
Node* cutTree(Node* root,int k)
{
    if(root==NULL)
        return NULL;
    if(root->data==k)
        return NULL;
    root->left=cutTree(root->left,k);
    root->right=cutTree(root->right,k);
    return root;
}
int height(Node* root)
{
    if(root==NULL)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    return (left>right)?left+1:right+1;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    Node* root=buildTree(a,n);
    root=cutTree(root,k);
    printf("%d",height(root));
    return 0;
}
