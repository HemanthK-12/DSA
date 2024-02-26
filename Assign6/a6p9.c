#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void insertMax(int arr[], int *n, int x)
{
    (*n)++;
    int i = *n - 1;
    arr[i] = x;
    while (i != 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    maxHeapify(arr, *n, 0);
}
void insertMin(int arr[], int *n, int x)
{
    (*n)++;
    int i = *n - 1;
    arr[i] = x;
    while (i != 0 && arr[(i - 1) / 2] > arr[i])
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    minHeapify(arr, *n, 0);
}
int getMedian(int maxHeap[], int sizeMax, int minHeap[], int sizeMin)
{
    if (sizeMax >= sizeMin)
        return maxHeap[0];
    else
        return minHeap[0];
}
int main()
{
    int q;
    scanf("%d", &q);
    int *maxHeap = (int *)malloc(q * sizeof(int));
    int *minHeap = (int *)malloc(q * sizeof(int));
    int *medians = (int *)malloc(q * sizeof(int)); // Array to store medians
    int sizeMax = 0, sizeMin = 0, sizeMedians = 0; // Counter for medians array
    while (q--)
    {
        int query;
        scanf("%d", &query);
        if (query == 1)
        {
            int x;
            scanf("%d", &x);
            if (sizeMax == 0 || x < maxHeap[0])
                insertMax(maxHeap, &sizeMax, x);
            else
                insertMin(minHeap, &sizeMin, x);
            while (abs(sizeMax - sizeMin) > 1)
            {
                if (sizeMax > sizeMin)
                {
                    insertMin(minHeap, &sizeMin, maxHeap[0]);
                    maxHeap[0] = maxHeap[--sizeMax];
                    maxHeapify(maxHeap, sizeMax, 0);
                }
                else
                {
                    insertMax(maxHeap, &sizeMax, minHeap[0]);
                    minHeap[0] = minHeap[--sizeMin];
                    minHeapify(minHeap, sizeMin, 0);
                }
            }
        }
        else if (query == 2)
        {
            int median = getMedian(maxHeap, sizeMax, minHeap, sizeMin);
            medians[sizeMedians++] = median; // Store median instead of printing
        }
    }
    for (int i = 0; i < sizeMedians; i++)
        printf("%d\n", medians[i]);
    return 0;
}