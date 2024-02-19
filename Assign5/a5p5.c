#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=first;
    
}
int disappear(int n,int k){
    struct node *p=first;
    struct node *q=NULL;
    if(k==1){
        return n;
    }
    if (n == 1) {
        return 1;
    }
    while(n>1){
    for(int i=1;i<k;i++){
        q=p;
        p=p->next;
    }
     q->next=p->next;
     if(p==first){
         p=p->next;
     }

    
    p=q->next;
    n--;
    }
return p->data;

}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    create(a,n);
    printf("%d",disappear(n,k));


}
