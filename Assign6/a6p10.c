#include <stdio.h>
#include <stdlib.h>
void Sort(int starts[], int ends[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (starts[j] > starts[j + 1])
            {
                int tempStart = starts[j];
                starts[j] = starts[j + 1];
                starts[j + 1] = tempStart;

                int tempEnd = ends[j];
                ends[j] = ends[j + 1];
                ends[j + 1] = tempEnd;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int starts[n], ends[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &starts[i], &ends[i]);
    bubbleSort(starts, ends, n);
    int m = 0;
    for (int i = 1; i < n; i++)
    {
        if (ends[m] >= starts[i])
            ends[m] = (ends[m] > ends[i]) ? ends[m] : ends[i];
        else
        {
            m++;
            starts[m] = starts[i];
            ends[m] = ends[i];
        }
    }
    printf("%d\n", m + 1);
    for (int i = 0; i <= m; i++)
        printf("%d %d\n", starts[i], ends[i]);
    return 0;
}