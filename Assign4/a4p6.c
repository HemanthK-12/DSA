#include <stdio.h>
#include <string.h>

int n, k, a[21], arr[21][26];

int solve(int i, int sum)
{
    if (sum == k)
        return 1;
    if (i > n || sum > k)
        return 0;
    if (arr[i][sum] != -1)
        return arr[i][sum];
    arr[i][sum] = solve(i, sum + a[i]) + solve(i + 1, sum);
    return arr[i][sum];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(arr, -1, sizeof(arr));
    printf("%d\n", solve(1, 0));
    return 0;
}