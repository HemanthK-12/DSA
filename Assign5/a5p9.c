#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *next;
}*first=NULL,*second=NULL;
void create(char s[],int n){
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=s[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=s[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}
void create2(char s[],int n){
    struct node *t,*last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=s[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=s[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}
void reverse(struct node *q,struct node *p){
    if(p!=NULL){
        reverse(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
int palindrome(){
    
    while(second!=NULL && first!=NULL){
        if(first->data!=second->data){
            return 0;
        }
        first=first->next;
        second=second->next;
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);

    s[n]='\0';
    create(s,n);
    create2(s,n);
    reverse(NULL,first);
    palindrome();
    if(palindrome()){
        printf("YES");
    }
    else{
        printf("NO");
    }
}