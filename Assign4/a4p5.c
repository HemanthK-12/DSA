#include <stdio.h>
#include <string.h>

#define MAXN 16
#define MAXK 144
#define MAXM 7
#define MOD 1000000007

typedef long long ll;

int n, m, k, digit[MAXN + 1], dp[MAXM + 1][MAXK + 1][1 << MAXM];
ll l, r, ten[MAXM + 1], power10[MAXN + 1], dp2[MAXM + 1][MAXK + 1][1 << MAXM];

ll solve(int i, int sum, int mask, ll num, ll L, ll R) {
    if (i > n) {
        return sum == k && L <= num && num <= R;
    }
    if (dp[i][sum][mask] != -1) {
        return dp[i][sum][mask];
    }
    ll res = 0;
    for (int d = 0; d <= 9; d++) {
        if (digit[i] != -1 && digit[i] != d) {
            continue;
        }
        if ((mask >> d) & 1) {
            continue;
        }
        int newSum = sum + d;
        if (newSum > k) {
            break;
        }
        ll newNum = num + d * power10[n - i];
        int newMask = mask;
        if (d > 0 && i <= m) {
            newMask |= 1 << d;
        }
        res += solve(i + 1, newSum, newMask, newNum, L, R);
    }
    return dp[i][sum][mask] = res;
}

int main() {
    scanf("%d %d %lld %lld", &n, &k, &l, &r);
    char s[MAXN + 1];
    scanf("%s", s);
    memset(digit, -1, sizeof(digit));
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] != '?') {
            digit[i] = s[i - 1] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    power10[0] = 1;
    for (int i = 1; i <= n; i++) {
        power10[i] = power10[i - 1] * 10;
    }
    printf("%lld\n", solve(1, 0, 0, 0, l, r));
    return 0;
}