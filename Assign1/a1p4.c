/*
Input
The first line contains a single integer N (0 ≤ N ≤ 10 10000 ).
Output
Print the number of 1s present in the binary representation of N .
*/
#include<stdio.h>
#include<gmp.h>
int main()
{
	mpz_t q,r,a;
	int n=0;
	mpz_inits(a,q,r,NULL);

	gmp_scanf("%Zd",&a);

	while(1)
	{
		mpz_mdivmod_ui(q,r,a,2);
		if(mpz_cmp_ui(r,1)==0)
			n++;
		mpz_set(a,q);
		if(mpz_cmp_ui(q,1)==0)
			break;
	}

	printf("%d",n+1);

	return 0;
}
