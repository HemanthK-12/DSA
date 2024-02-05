/*
Input
First line contains an integer n (1 ≤ n ≤ 105).
Second line contains n integers in an array a (1 ≤ ai ≤ 109).
Your solution should run in O(n) time complexity.
Output
The max sum where both sums are equal
*/
#include <stdio.h>
//This also uses two pointer approach
int maxweight(int n, int a[])
{
    int i = 0, j = n - 1;
    int leftSum = 0, rightSum = 0, maxSum = 0;

    while (i <= j)
    {
        if (leftSum <= rightSum)
            leftSum += a[i++];
        else 
            rightSum += a[j--];
        if (leftSum == rightSum)
            maxSum = leftSum;
    }
    return maxSum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", maxweight(n, a));
    return 0;
}