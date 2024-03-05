#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int val;
    int count;
    int first_idx;
} Element;
int compare(const void *a, const void *b)
{
    Element *elemA = (Element *)a;
    Element *elemB = (Element *)b;
    if (elemA->count != elemB->count)
        return elemA->count - elemB->count;
    else
        return elemA->first_idx - elemB->first_idx;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    Element elements[n + 1];
    for (int i = 0; i <= n; i++)
    {
        elements[i].val = i;
        elements[i].count = 0;
        elements[i].first_idx = n;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        elements[arr[i]].count++;
        if (elements[arr[i]].first_idx == n)
            elements[arr[i]].first_idx = i;
    }
    qsort(elements, n + 1, sizeof(Element), compare);
    int idx = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < elements[i].count; j++)
            arr[idx++] = elements[i].val;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}