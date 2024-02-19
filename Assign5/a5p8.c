#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[]){
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void insert_first(int x){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=first;
    t->prev=NULL;
    first->prev=t;
    first=t;
}
void insert_last(int x){
    struct node *p=first;
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    for(int i=1;i<n;i++){
        p=p->next;
    }
    t->next=NULL;
    t->prev=p;
    p->next=t;
}
void delete_first(){
    struct node *p=first;
    first=first->next;
    free(p);
    if(first){
        first->prev=NULL;
    }    
}
void delete_last() {
    if (first == NULL) {
        printf("-1\n"); // Handle case where the list is empty
        return;
    }
    struct node *p = first;
    while (p->next != NULL) {
        p = p->next;
    }

    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else {
        // If p->prev is NULL, it means p is the only node in the list
        first = NULL;
    }
    free(p);
}

void display(struct node *p){
    if(p==NULL){
        printf("-1\n");
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void rev_display(struct node *p){
    if(p==NULL){
        printf("-1\n");
    }
    while (p->next != NULL) {
        p = p->next;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}
int main(){
    int q;
    scanf("%d %d",&n,&q);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    create(a);
    for(int i=0;i<q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int element;
            scanf("%d",&element);
            insert_first(element);
        }
        else if(op==2){
            int element;
            scanf("%d",&element);
            insert_last(element);
        }
        else if(op==3){
            delete_first();
        }
        else if(op==4){
            delete_last();
        } else if (op == 5) {
    display(first);
} else if (op == 6) {
    rev_display(first);
}

    }

}