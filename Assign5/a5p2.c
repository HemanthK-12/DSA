#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL;

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
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
struct node *merge(struct node *p, struct node *q)
{
    struct node *last, *third;
    if (p->data < q->data)
    {
        last = third = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        last = third = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    if (q != NULL)
    {
        last->next = q;
    }
    return third;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m], b[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    create(a, m);
    create2(b, n);
    merge(first, second);
    struct node *third = (first, second);
    display(third);
}