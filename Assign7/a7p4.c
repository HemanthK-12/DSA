#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n],exists[n+1];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n+1; i++)
        exists[i] = 0;
    for (int i = 0; i < n; i++)
        exists[arr[i]] = 1;
    int l = 1, r = n;
    while (l < r)
    {
        if (!exists[l] && !exists[r] && l + r == k)
        {
            printf("yes\n");
            return 0;
        }
        if (l + r < k)
            l++;
        else
            r--;
    }
    printf("no\n");
    return 0;
}