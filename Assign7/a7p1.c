#include <stdio.h>
void sort_indices(int arr[], int n, int exp, int k)
{
    int temp[n],count[16]={0};//because hexadecimal,so 16
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 16]++;//number of times each digit comes in the input
    for (int i = 1; i < 16; i++)
        count[i] += count[i - 1];//stores position in which they occur because stable sorting,i.e. if numbers same,sort in the same order as initial
    for (int i = n - 1; i >= 0; i--)
    {//this'll sort array based on that index and the order in which they appeared also
        temp[count[(arr[i] / exp) % 16] - 1] = arr[i];
        count[(arr[i] / exp) % 16]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];//storing the sorted index array into the final array
    if (k == 0)
        for (int i = 0; i < n; i++)
            printf("%x ", arr[i]);//to print array when the given digit is reached
}
void radixsort(int arr[], int n, int k)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];//finding maximum so that we'll know till how many indices we shoudl continue the loop
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