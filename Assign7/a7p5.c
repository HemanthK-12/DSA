#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int first;
    int second;
} Pair;
int compare(const void *a, const void *b)
{
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    if (pairA->first != pairB->first)
        return pairA->first - pairB->first;
    else
        return pairA->second - pairB->second;
}
int main()
{
    int n;
    scanf("%d", &n);
    Pair pairs[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &pairs[i].first);
    for (int i = 0; i < n; i++)
        scanf("%d", &pairs[i].second);
    qsort(pairs, n, sizeof(Pair), compare);
    for (int i = 0; i < n; i++)
        printf("%d ", pairs[i].first);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", pairs[i].second);
    return 0;
}