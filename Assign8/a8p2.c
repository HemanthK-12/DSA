#include <stdio.h>
#include <stdlib.h>
void printKMax(int arr[], int n, int k)
{

    int *Qi = (int *)malloc(sizeof(int) * n);
    int front = 0,rear = -1,i;
    for (i = 0; i < k; ++i)
    {
        while (front <= rear && arr[i] >= arr[Qi[rear]])
            rear--;
        Qi[++rear] = i;
    }
    for (; i < n; ++i)
    {
        printf("%d ", arr[Qi[front]]);
        while (front <= rear && Qi[front] <= i - k)
            front++;
        while (front <= rear && arr[i] >= arr[Qi[rear]])
            rear--;
        Qi[++rear] = i;
    }
    printf("%d\n", arr[Qi[front]]);
}
int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printKMax(arr, n, k);
    return 0;
}