/*
Input
The first line contains an integer n (1 ≤ n ≤ 105).
The second line contains a string of length n consisting of only lowercase English alphabet and
whitespace.
Your solution should run in O(n) time complexity.
Bonus: Can you solve it using only constant extra space?
Output
A string whose order of vowels are reversed.
*/
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