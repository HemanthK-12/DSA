/*
Input
The first line contains two integers n and m (1 ≤ n, m ≤ 105).
The second line contains n integers of the first array (1 ≤ a1 ≤ a2 ... ≤ an−1 ≤ an ≤ 109).
The third line contains n integers of the second array (1 ≤ b1 ≤ b2 ... ≤ bn−1 ≤ bn ≤ 109).
Your solution should run in O(n+m) time complexity.
Output
array with merged elements in sorted order.
*/
#include<stdio.h>
void mergeArrays(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i<n && j <m)
    {
        if (a[i] < b[j])
            printf("%d ",a[i++]);
        else
            printf("%d ",b[j++]);
    }
    while (i < n)
        printf("%d ",a[i++]);
    while (j < m)
        printf("%d ",b[j++]);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n],b[m];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    scanf("%d",&b[i]);
    mergeArrays(a,b,n,m);

}