#include<stdio.h>
int reversewords(char str[],int n)
{
    int start=0;int end=1;
    for(int i=1;i<n;i++)
    {
        int l=i-1;
        int h=i;
        while(l>=0 && h<n && str[l]==str[h])
        {
            if(h-l+1>end)
            {start=l;
            end=h-l+1;}
        
        l--;
        h++;
        }
    }
    for(int i=1;i<n;i++)
    {
        int l=i-1;
        int h=i+1;
        while(l>=0 && h<n && str[l]==str[n])
        {
            if(h-l+1>end)
            {start=l;
            end=h-l+1;}
        
        l--;
        h++;
        }
    }
    return end;
}
int main()
{
    int n;
    scanf("%d",&n);
    char str[n];
    scanf("%s",str);
    printf("%d",reversewords(str,n));   
}