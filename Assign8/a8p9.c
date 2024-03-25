#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
        if (arr[j] <= x)
            swap(&arr[i++], &arr[j]);
    swap(&arr[i], &arr[r]);
    return i;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int findMedian(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);
    return arr[n / 2];
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", kthSmallest(arr, 0, n - 1, n - k + 1));
    return 0;
}