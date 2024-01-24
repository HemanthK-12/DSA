#include <stdio.h>

int main()
{
	char num1[1000], num2[1000];
	scanf("%s",num1);
	scanf("%s",num2);
	
	int len1=0;
	int len2=0;
	
	while(num1[len1]!='\0')
	{
		len1++;
	}
	while(num2[len2]!='\0')
	{
		len2++;
	}
	
	int prod[2001];
	
	for(int i=0; i<len1; i++)
	{
		for(int j=0; j<len2; j++)
		{
			int dig1=num1[len1-i-1]-'0';
			int dig2=num2[len2-j-1]-'0';
			
			prod[i+j]+=dig1*dig2;
			prod[i+j+1]+=prod[i+j]/10;
			prod[i+j]=prod[i+j]%10;
		}	
	}
	
	int prodlen=len1+len2;
	while(prod[prodlen-1]==0 && prodlen>1)
	{
		prodlen--;
	}
	char result[prodlen];
	for(int i=prodlen-1; i>=0; i--)
	{
		result[i]=prod[i]+'0';
		printf("%c",result[i]);
	}
	//printf("%s\n",result);
}
