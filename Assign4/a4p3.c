#include <stdio.h>
#include <string.h>

int n, k, a[21], t[21], dp[21][10001];
int max(int a, int b)
{return a > b ? a : b;}
int solve(int i, int j)
{
    if (i > n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (j < t[i])
        return dp[i][j] = solve(i + 1, j);
    else
        return dp[i][j] = max(solve(i + 1, j), solve(i + 1, j - t[i]) + a[i]);
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(1, k));
    return 0;
}