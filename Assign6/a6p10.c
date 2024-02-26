#include <stdio.h>
#include <stdlib.h>
typedef struct Slot
{
    int start;
    int end;
} Slot;
void bubbleSort(Slot slots[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (slots[j].start > slots[j + 1].start)
            {
                Slot temp = slots[j];
                slots[j] = slots[j + 1];
                slots[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Slot slots[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &slots[i].start, &slots[i].end);
    bubbleSort(slots, n);
    int m = 0;
    for (int i = 1; i < n; i++)
    {
        if (slots[m].end >= slots[i].start)
            slots[m].end = slots[m].end > slots[i].end ? slots[m].end : slots[i].end;
        else
            slots[++m] = slots[i];
    }
    printf("%d\n", m + 1);
    for (int i = 0; i <= m; i++)
        printf("%d %d\n", slots[i].start, slots[i].end);
    return 0;
}