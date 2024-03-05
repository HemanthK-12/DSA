#include <stdio.h>
void sort_indices(int arr[], int n, int exp, int k)
{
    int temp[n],count[16]={0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 16]++;
    for (int i = 1; i < 16; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[(arr[i] / exp) % 16] - 1] = arr[i];
        count[(arr[i] / exp) % 16]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    if (k == 0)
        for (int i = 0; i < n; i++)
            printf("%x ", arr[i]);
}
void radixsort(int arr[], int n, int k)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int i = 1; max / i > 0; i *= 16)
        if(k>0)
            sort_indices(arr, n, i, --k);
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%x", &a[i]);
    radixsort(a, n, k);
    return 0;
}