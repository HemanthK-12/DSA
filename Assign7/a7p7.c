#include <stdio.h>
#include <limits.h>
typedef struct Val
{
    int abs_pos;
    int ini_val;
} Val;
void swap(Val *a, Val *b)
{
    Val tmp = *a;
    *a = *b;
    *b = tmp;
}
void moveLefts(Val a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].abs_pos == a[j].abs_pos && a[i].ini_val > a[j].ini_val)
                swap(&a[i], &a[j]);
}
void heapify(Val a[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l].abs_pos < a[smallest].abs_pos)
        smallest = l;
    if (r < n && a[r].abs_pos < a[smallest].abs_pos)
        smallest = r;
    if (smallest != i)
    {
        swap(&a[i], &a[smallest]);
        heapify(a, n, smallest);
    }
}
int main()
{
    int n, k, x;
    scanf("%d %d %d", &n,&k,&x);
    Val a[n];
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        a[i].ini_val = s;
        a[i].abs_pos = (s < x) ? x - s : s - x;
    }
    for (int i = n - 1; i >= 0; i--)
        heapify(a, n, i);
    moveLefts(a, n);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", a[0].ini_val);
        a[0].abs_pos = INT_MAX;
        heapify(a, n, 0);
        moveLefts(a, n);
    }
}