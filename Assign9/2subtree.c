#include<stdio.h>
#include<stdlib.h>
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
Node* BuildTree(int n, int A[])
{
    if(n<=0)
        return NULL;
    Node** newNode = (Node**)malloc(n * sizeof(Node));
    for(int i=0; i<n; i++)
    {
        if(A[i] == -1)
            newNode[i] = NULL;
        else
            newNode[i] = CreateNode(A[i]);
    }
    Node* root = newNode[0];
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(newNode[i] == NULL)
            count++;
        if(newNode[i])
        {
            int leftIndex = 2*i + 1 - 2*count;
            int rightIndex = 2*i + 2 - 2*count;
            if(leftIndex < n)
                newNode[i]->left = newNode[leftIndex];
            if(rightIndex < n)
                newNode[i]->right = newNode[rightIndex];
        }
    }
    free(newNode);
    return root;
}
int isIdentical(Node* rootA, Node* rootB)
{
    if(rootA == NULL && rootB == NULL)
        return 1;   
    if(rootA == NULL || rootB == NULL)
        return 0;
    if(rootA->data != rootB->data)
        return 0;
    return isIdentical(rootA->left, rootB->left) && isIdentical(rootA->right, rootB->right);
}
int isSubtree(Node* rootA, Node* rootB)
{
    if(rootB == NULL)
        return 1;
    if(rootA == NULL)
        return 0;
    if(isIdentical(rootA, rootB))
        return 1;
    return isSubtree(rootA->left, rootB) || isSubtree(rootA->right, rootB);
}
void main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    int B[m];
    for(int i=0; i<m; i++)
        scanf("%d",&B[i]);
    Node* rootA = insertlevelorder(A,rootA,0,n);
    Node* rootB = insertlevelorder(B,rootB,0,m);
    if(isSubtree(rootA, rootB))
        printf("WIN");
    else
        printf("LOSS");
}

// #include <stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// };
// struct node *createnode(int data){
//     struct node *newnode=(struct node *)malloc(sizeof(struct node));
//     newnode->left=NULL;
//     newnode->data=data;
//     newnode->right=NULL;
//     return newnode;
// }
// struct node* createTree(int arr[], int start, int end) {
//     if (start > end || arr[start] == -1) {
//         return NULL;
//     }

//     struct node *root = createnode(arr[start]);

//     root->left = createTree(arr, start*2 + 1, end);
//     root->right = createTree(arr, start*2 + 2, end);

//     return root;
// }
// int isidentical(struct node *root,struct node *subtree){
//     if(root==NULL && subtree==NULL){
//         return 1;
//     }
//     if(root!=NULL && subtree!=NULL){
//         if(root->data==subtree->data && isidentical(root->left,subtree->left) &&isidentical(root->right,subtree->right) ){
//             return 1;
//         }
//     }
//     return 0;
// }
// int subtree(struct node *root,struct node *subtree1){
//     if(root==NULL){
//         return 0;
//     }
//     if(subtree1==NULL){
//         return 1;
//     }
//     if(isidentical(root,subtree1)){
//         return 1;
//     }
//     return(subtree(root->left,subtree1)||subtree(root->right,subtree1));
// }
// int main(){
//     int n,k;
//     scanf("%d %d",&n,&k);
//     int a[n];
//     int b[k];
//     for(int i=0;i<n;i++){
//        scanf("%d",&a[i]);
//     }
//     for(int i=0;i<k;i++){
//         scanf("%d",&b[i]);
//     }
//     struct node *root=createTree(a,0,n);
//     struct node *subtree1=createTree(b,0,k);
//     if(subtree(root,subtree1)){
//         printf("YES");
//     }
//     else{
//         printf("NO");
//     }
// }