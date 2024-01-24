/*Input
Let N = 10^100000
The first line contains a single integer Num1.
The second line contains a single integer Num2.
(−10^N ≤ Num1, Num2 ≤ 10^N ).
Output
Print a single integer containing the product of the two long numbers provided to you.
*/
#include<stdio.h>
#include<gmp.h>
int main()
{
	mpz_t d,e,f;
	mpz_inits(d,e,f,NULL);

	gmp_scanf("%Zd",&d);
	gmp_scanf("%Zd",&e);
	
	mpz_mul(f,d,e);

	gmp_printf("%Zd",f%10);

	mpz_clear(d);
	mpz_clear(e);
	mpz_clear(f);
		
	return 0;
}
