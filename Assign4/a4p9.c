#include <stdio.h>
#include<math.h>

int main(void)
{
    int m,k;
    scanf("%d",&m);
    scanf("%d",&k);
    long long lowest = -1; 
    long long highest = -1;
    for(long long i = pow(10,m-1);i<pow(10,m);i++)
    {
        long long num = i;
        int sum=0;
        while(num>0)
        {
            sum += num %10;
            num = num/10;
            if(sum>k)
                break;
        }
        if(sum == k)
        {
            if(i>highest)
                highest = i;
            if(lowest == -1)
                lowest = i;
            if(i==power(10,m-1))
                break;
        }
    }
    printf("%lld %lld",lowest,highest);

}

