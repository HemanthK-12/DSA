/*
Input
The first line contains a single integer N (1 ≤ N ≤ 10 10000 ).
The second line contains a single integer M (1 ≤ M ≤ 10 10000 ).
Output
Print a single integer passcode P such that N*P mod M =1.
Soln:
xA mod B=1
int x=1;
while(1)
{
q=(xA-Bq)/B;
if(q<xA && xA-Bq==1)
  break;
  }
  printf(x)
*/
#include<stdio.h>
#include<gmp.h>
int main()
{
	mpz_t a,b,c;
	mpz_inits(a,b,c,NULL);

	gmp_scanf("%Zd",&a);
	gmp_scanf("%Zd",&b);

	mpz_invert(c,a,b);

	gmp_printf("%Zd",c);

	return 0;
}





