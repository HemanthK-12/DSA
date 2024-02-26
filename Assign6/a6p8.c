#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    int arrIdx;
    int nextIdx;
} Node;
void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(Node heap[], int i, int heapSize)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left].val < heap[smallest].val)
        smallest = left;
    if (right < heapSize && heap[right].val < heap[smallest].val)
        smallest = right;
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}
void buildHeap(Node heap[], int heapSize)
{
    for (int i = (heapSize - 2) / 2; i >= 0; i--)
        minHeapify(heap, i, heapSize);
}
void mergeKSortedArrays(int arr[][1000], int arrSize[], int k)
{
    Node heap[k];
    int i;
    for (i = 0; i < k; i++)
    {
        heap[i].val = arr[i][0];
        heap[i].arrIdx = i;
        heap[i].nextIdx = 1;
    }
    buildHeap(heap, k);
    while (1)
    {
        Node root = heap[0];
        printf("%d ", root.val);
        if (root.nextIdx < arrSize[root.arrIdx])
        {
            root.val = arr[root.arrIdx][root.nextIdx];
            root.nextIdx += 1;
        }
        else
            root = heap[k-- - 1];
        heap[0] = root;
        if (k <= 0)
            break;
        minHeapify(heap, 0, k);
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    int arr[k][1000];
    int arrSize[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arrSize[i]);
        for (int j = 0; j < arrSize[i]; j++)
            scanf("%d", &arr[i][j]);
    }
    mergeKSortedArrays(arr, arrSize, k);
    return 0;
}