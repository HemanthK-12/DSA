
#include <stdio.h>
int n, k;
long long a[100005], satisfied[60];
int current, max;

int max_clients()
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (a[i] & (1LL << j))
            {
                if (satisfied[j] == 0) current++;
                satisfied[j]++;
            }
        }
    }
    max = current;
    for (int i = k; i < n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (a[i - k] & (1LL << j))
            {
                satisfied[j]--;
                if (satisfied[j] == 0)
                    current--;
            }
            if (a[i] & (1LL << j))
            {
                if (satisfied[j] == 0)
                    current++;
                satisfied[j]++;
            }
        }
        if (current > max)
            max = current;
    }
    return max;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf("%lld", &a[i]);
    printf("%d\n", max_clients());
    return 0;
}