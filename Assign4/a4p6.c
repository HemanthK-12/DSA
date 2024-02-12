#include <stdio.h>
#include <string.h>

int n, k, a[21], dp[21][26];

int solve(int i, int sum) {
    if (sum == k)
        return 1;
    if (i > n || sum > k)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    dp[i][sum] = solve(i, sum + a[i]) + solve(i + 1, sum);
    return dp[i][sum];
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(1, 0));
    return 0;
}