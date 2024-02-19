#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=first;

}
int answer(int a,int b,int n){
    struct node*p=first;
    struct node *q=first;
    for(int i=1;i<a;i++){
        p=p->next;
    }
     for(int i=1;i<b;i++){
        q=q->next;
    }
    while(p->data != q->data){
        p=p->next->next;
        q=q->next;
    }
    return p->data;
}
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int a1[n];
    for(int i=0;i<n;i++){
        a1[i]=i+1;
    }
    create(a1,n);
    int ans=answer(a,b,n);
    printf("%d",ans);

}