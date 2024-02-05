#include<stdio.h>
long long int modulus=1000000007;
long long int power(long long int base, long long int exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 0)
        return power((base * base) % modulus, exponent / 2) % modulus;
    else
        return (base * power((base * base) % modulus, (exponent - 1) / 2)) % modulus;
}
int main()
{
    int n;
    long long int pro=1;
    scanf("%d",&n);
    long long int a[n],b[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]);
    for(int i = 0; i < n; i++)
    {
        long long int product=((long long int)(power(a[i],b[i])));
        pro=(pro*product)%modulus;
    }
    printf("%lld",pro);
    return 0;
}