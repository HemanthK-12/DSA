#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0,j = 0,k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r)/ 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void nomkiSort(int arr[], int low, int high, int depth)
{
    if (low < high)
    {
        if (depth == 0)
            mergeSort(arr, low, high);
        else
        {
            int pi = partition(arr, low, high);
            nomkiSort(arr, low, pi - 1, depth - 1);
            nomkiSort(arr, pi + 1, high, depth - 1);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int depth = 2 * log2(n);
    nomkiSort(arr, 0, n - 1, depth);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}