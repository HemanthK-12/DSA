#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int top;
    int data[1000000];
    int min[1000000];
} Stack;
long long findSubarrays(int arr[], int n, int k)
{
    long long count = 0;
    int left = 0, right = 0;
    int max = arr[0], min = arr[0];
    while (right < n)
    {
        if (arr[right] > max)
            max = arr[right];
        if (arr[right] < min)
            min = arr[right];
        while (max - min > k)
        {
            if (arr[left] == max)
            {
                max = arr[left + 1];
                for (int i = left + 2; i <= right; i++)
                    if (arr[i] > max)
                        max = arr[i];
            }
            if (arr[left] == min)
            {
                min = arr[left + 1];
                for (int i = left + 2; i <= right; i++)
                    if (arr[i] < min)
                        min = arr[i];
            }
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%lld\n", findSubarrays(arr, n, k));
    return 0;
}