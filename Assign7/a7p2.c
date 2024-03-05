#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    float data;
    struct Node *next;
} Node;
Node *insert(Node *head, float data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (!head)
        return node;
    if (data < head->data)
        node->next = head;
        return node;
    Node *current = head;
    while (current->next && current->next->data < data)
        current = current->next;
    node->next = current->next;
    current->next = node;
    return head;
}
int main()
{
    int n;
    scanf("%d", &n);
    Node *buckets[n];
    int counts[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
        counts[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        float num;
        scanf("%f", &num);

        int index = num * n;
        buckets[index] = insert(buckets[index], num);
        counts[index]++;
    }
    for (int i = 0; i < n; i++)
    {
        Node *current = buckets[i];
        while (current)
        {
            printf("%.1f ", current->data);
            current = current->next;
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", counts[i]);
    return 0;
}