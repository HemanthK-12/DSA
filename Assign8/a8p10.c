#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
        if (arr[j] <= pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];
    int pi = partition(arr, low, high);
    int dist = pi - low + 1;
    if (dist == k)
        return arr[pi];
    else if (dist > k)
        return quickSelect(arr, low, pi - 1, k);
    else
        return quickSelect(arr, pi + 1, high, k - dist);
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", quickSelect(arr, 0, n - 1, n - k + 1));
    return 0;
}