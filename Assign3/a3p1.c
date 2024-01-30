#include<stdio.h>
int palindrome(char a[])
{
    int length;
    for(int i=0;i<3000;i++)
    {
        if(a[i]=='\0')
        {
            length=i;
            break;
        }
    }
    int l=(length%2)?length+1:length;
    int c=0;
    for(int i=0;i<l/2;i++)
    {
        if(a[i]==a[l-i-1])
            c++;
    }
    if(c==l/2)
    return 1;
    else
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    char b[n];
    int length[n];
    int j=0,max=0;
    for(int i=0;i<n;i++)
    {
        
            b[i]=a[j+i];
            if(palindrome(b))
            {
                max=(max>i)?max:i;
            }
            else if(!(palindrome(b)) && i==n-1)
            {
                b[0]='\0';
                i=0;
                j++;
            }

        
    }
    return 0;
}