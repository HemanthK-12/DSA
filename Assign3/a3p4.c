#include<stdio.h>
int main()
{
    int n,j=0;
    scanf("%d",&n);
    char str[n],b[n];
    scanf(" %[^\n]",str);
    int num[n];
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        { 
            num[i]=-1;
            b[j++]=str[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(num[i]==-1)
        printf("%c",b[(j--)-1]);
        else
        printf("%c",str[i]);
    }
}