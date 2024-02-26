#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
void create(int a[], int n)
{
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int a[], int n)
{
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create3()
{
    struct node *t, *last;
    struct node *p = first;
    struct node *q = second;
    int carry = 0;
    while (p != NULL || q != NULL)
    {
        int x = (p != NULL) ? p->data : 0;
        int y = (q != NULL) ? q->data : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = sum % 10;
        t->next = NULL;
        if (third == NULL)
        {
            third = t;
            last = third;
        }
        else
        {
            last->next = t;
            last = t;
        }
        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }
    if (carry > 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = carry;
        t->next = NULL;
        last->next = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m], b[n];
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    create(a, m);
    create2(b, n);
    create3();
    display(third);
}