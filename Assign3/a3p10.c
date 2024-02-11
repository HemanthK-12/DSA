#include<stdio.h>
#define ll long long int
ll modulus=1000000007;
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return power((a * a) % modulus, b / 2) % modulus;
    else
        return (a * power((a * a) % modulus, (b - 1) / 2)) % modulus;
}
int main()
{
    int n;
    ll pro=1;
    scanf("%d",&n);
    ll a[n],b[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]);
    for(int i = 0; i < n; i++)
        pro=(pro*power(a[i],b[i]))%modulus;
    printf("%lld",pro);
    return 0;
}