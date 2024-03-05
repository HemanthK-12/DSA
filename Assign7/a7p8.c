#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dps;
    int synergy;
} Character;
Character heap[100000];
int heapSize = 0;
void push(Character value)
{
    int i = heapSize++;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent].dps >= value.dps)
            break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = value;
}
Character pop()
{
    Character ret = heap[0];
    Character value = heap[--heapSize];
    int i = 0;
    while (i * 2 + 1 < heapSize)
    {
        int child = i * 2 + 1;
        if (child + 1 < heapSize && heap[child].dps < heap[child + 1].dps)
            child++;
        if (heap[child].dps <= value.dps)
            break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = value;
    return ret;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    Character characters[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &characters[i].dps);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &characters[i].synergy);
        if (characters[i].synergy > 0)
            push(characters[i]);
    }
    long long goodness = 0;
    while (heapSize > 0 && k > 0)
    {
        Character top = pop();
        goodness += top.dps + top.synergy;
        k--;
    }
    printf("%lld", goodness);
    return 0;
}