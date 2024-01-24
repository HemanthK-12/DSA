#include<stdio.h>
int digits(char n[])
{
	int len=0;
	for(int i=0;i<1000;i++)
	{
		if(n[i]=='\0')
		{
			len=i;
			break;
		}
	}
	return len;
}
int main()
{
	char a[1000],b[1000];

	scanf("%s",a);
	scanf("%s",b);
	
	int len_a=digits(a);
	int len_b=digits(b);
	
	char product[(len_a*len_a)];

	int pro=0,lastdigit=0;

	for(int i=len_a-1;i>=0;i--)
	{
		pro+=(a[i]*b[0])-(48*(a[i]+b[0]))+2304;
		lastdigit=(pro)%10;
		product[(len_a*len_a)+i-(len_a)]=lastdigit+'0';
		if(pro>9)
			pro=((pro-lastdigit)/10);
		else
			pro=0;
		if(i==0 && pro>0)
			product[(len_a*len_a)-len_a-1]=pro;
	}

	for(int i=0;i<(len_a*len_a)-1;i++)
	{
		printf("%c",product[i]);
	}
}


		

