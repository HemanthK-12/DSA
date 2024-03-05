#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void maxheap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}
int ans(char a[], int n, int k)
{
    int count[26];
    for (int i = 0; i < 26; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[a[i] - 'a']++;
    maxheap(count, 26);
    for (int i = 0; i < n - k; i++)
    {
        count[0] = count[0] - 1;
        heapify(count, 26, 0);
    }
    int minsum = 0;
    for (int i = 0; i < 26; i++)
        minsum += (count[i] * count[i]);
    return minsum;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char a[n + 1];
    for (int i = 0; i < n; i++)
        scanf(" %c", &a[i]);
    printf("%d", ans(a, n, k));
}