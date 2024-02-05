#include <stdio.h>
#define llint long long int
int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  llint arr[n];
  for(int i=0;i<n;i++)
    scanf("%lld",&arr[i]);

  for(int i=0;i<n;i++)
  {
    for(llint j=59;j>=0;j--)
    {
    llint a=(arr[i])&((llint)1<<j);
    a=(a==0)?0:1;
    printf("%lld",a);
    }
    printf("\n");
  }
  return 0;
}