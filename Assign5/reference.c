/*
Input
The first line contains 2 positive integers n and m (1 ≤ n, m ≤ 106) - the number of digits in the
two numbers respectively.
The second line contains n digits of an integer a in reverse order, where each digit in a is from 0 to
9, both inclusive.
The third line contains m digits of an integer b in reverse order, where each digit in b is from 0 to
9, both inclusive.
Note: The last digit in each of the inputs of second and third line will NOT be 0.
Output
A linked list, consisting of the the sum of the original numbers, but in reverse.
4 5
1 2 3 4
5 6 7 8 9
answer will be 4321+98765(=103086) but in reverse,i.e. 6 8 0 3 0 1
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void llprint(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node* insertstart(struct Node* head,int data)
{
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node* insertIndex(struct Node*head,int data,int index)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * temphead=head;
    int i=0;
    while(i!=index-1)
    {
        temphead=temphead->next;
        i++;         
    }
    ptr->data=data;
    ptr->next=temphead->next;
    temphead->next=ptr;
    return head;
}

void insertmiddle(struct Node*ptr,struct Node* a)
{
    ptr->data=((a->data)+((a->next)->data))/2;
    ptr->next=a->next;
    a->next=ptr;
}
void insertend(struct Node* ptr,struct Node* head)
{
    while(1)
    {
        if((head->next)==NULL)
        {
            head->next=ptr;
            ptr->data=9999;
            ptr->next=NULL;
            break;
        }
        else
        head=head->next;
    }
}
int main()
{
    struct Node * head=(struct Node *)malloc(sizeof(struct Node));
    struct Node * two=(struct Node *)malloc(sizeof(struct Node));
    struct Node * three=(struct Node *)malloc(sizeof(struct Node));
    struct Node * four=(struct Node *)malloc(sizeof(struct Node));
    struct Node * five=(struct Node *)malloc(sizeof(struct Node));
    struct Node * tail=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=two;

    two->data=2;
    two->next=three;

    three->data=3;
    three->next=four;

    four->data=4;
    four->next=five;

    five->data=6;
    five->next=tail;

    tail->data=7;
    tail->next=NULL;
    llprint(insertstart(head,0));
    printf("\n");

    //llprint(starting);
    //insertmiddle(middling,a);
    printf("\n");

    //llprint(starting);
    //insertend(ending,head);
    printf("\n");

    //llprint(starting);
    return 0;
}
