#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long

ll solve(ll k, ll l, ll r, char *s, ll index, ll temp) {
    if (index == strlen(s))
    {
        if (k == 0 && temp>0 && temp<=r) 
            return 1;
        return 0;
    }
    ll take = 0, notTake = 0;
    if (s[index] == '?')
    {
        for (int i = 0; i < 10; i++)
        {
            if (index == 0 && i == 0)
                continue;
            if (i <= k)
            {
                temp = temp * 10 + i;
                take += solve(k - i, l, r, s, index + 1, temp);
                temp = temp / 10;
            }
        }
    }
    else
    {
        int i = s[index] - '0';
        temp = temp * 10 + i;
        notTake += solve(k, l, r, s, index + 1, temp);
        temp = temp / 10;
    }
    return take + notTake;
}

int main()
{
    ll n, k, l, r;
    scanf("%lld %lld %lld %lld", &n, &k, &l, &r);
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    for (ll i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            int num = ch - '0';
            k = k - num;
        }
    }
    printf("%lld\n", solve(k, l, r, s, 0, 0));
    free(s);
}