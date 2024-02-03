#include <stdio.h>

void bin_store(long long int n, int binary[][60], int row)
{
  for (int i =59; i >= 0;i--)
  {
    binary[row][i] = n % 2;
    n /= 2;
  }
}
int main() {
  long long int n,k;
  scanf("%lld %lld", &n,&k);
  int binary[n][60];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <60; j++)
      binary[i][j] = 0;
  long long int number[n];
  for (int i = 0; i < n; i++)
    scanf("%lld", &number[i]);
  for (int i = 0; i < n; i++)
    bin_store(number[i], binary, i);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <60; j++)
      printf("%d", binary[i][j]);
    printf("\n");
  }
  return 0;
}