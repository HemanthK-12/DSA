#include<stdio.h>
//This uses sliding window
int main() {
    int n, k, x, c = 0;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < k; i++)
        sum += a[i];

    for(int i = k; i <= n; i++)
    {
        if(sum >= x * k)
            c++;    
        if(i < n)
            sum = sum - a[i - k] + a[i];
    }
    printf("%d", c);
    return 0;
}