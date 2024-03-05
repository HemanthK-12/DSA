#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int hp;
    int index;
} Character;
Character heap[100000];
int heapSize = 0;
void push(Character value)
{
    int i = heapSize++;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent].hp <= value.hp)
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
        if (child + 1 < heapSize && heap[child].hp > heap[child + 1].hp)
            child++;
        if (heap[child].hp >= value.hp)
            break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = value;
    return ret;
}
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        int hp;
        scanf("%d", &hp);
        if (hp < x)
        {
            Character character = {hp, i + 1};
            push(character);
        }
    }
    printf("%d\n", heapSize);
    while (heapSize > 0)
        printf("%d ", pop().index);
    return 0;
}