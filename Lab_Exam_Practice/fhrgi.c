#include<string.h>
typedef struct node
{
    char data;
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
    if(top!=NULL)
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp=top;
        top=top->next;
        free(temp);
    }
}
char peek()
{
    if(top!=NULL)
    {
        return top->data;
    }
    else
        return '1';
}
int size()
{
    int c=0;
    Node*temp=(Node*)malloc(sizeof(Node));
    temp=top;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
char* simplifyPath(char* path)
{
    int n=strlen(path);
    int final[n],j=0;
    for(int i=0;i<n;i++)
        push((*(path+i)));
    for(int i=0;i<n;i++)
    {
        char a=peek();
        if(a=='/' && i==0)
            pop();
        else if((a=='.' || (*(path+(n-i))=='.') && (*(path+(n-i+1)))!='.' ))
            pop();
        else if(a=='/' && (*(path+(n-i)))=='/')
            pop();
        else
            {
                final[j++]=peek();
                pop();
            }
    }
    char* canonicalpath=(char*)malloc(j*sizeof(char));
    for(int i=j-1;i>=0;i--)
    {
        int k=j-i-1;
        //(*(canonicalpath+k))=final[i];
        printf("%c",final[i]);
    }    
    return canonicalpath;
}




