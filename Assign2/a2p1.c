/*
Input
The first line contains a two integer N and H (1 ≤N ≤106) and (1 ≤H ≤109) - the number of
bamboos in the bunch and the height of the bamboo Nom loves respectively.
The second line contains an array of size N containing (a0, a1, . . . , aN−1) where (1 ≤ai ≤109) -
heights of different bamboos sorted in ascending order.
Output
A single integer, position of the bamboo in the bunch (array). Assume 1-based indexing.
Your solution should run in O(logN) time complexity.
*/
#include <stdio.h>

int binarySearch(int arr[],int r, int x)
{
    int l=0;
    while (l <= r)
    {
        int mid = (r+l)/2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid + 1;  // 1-based indexing

        // If x greater, ignore left half
        if (arr[mid] < x)
            l = mid + 1;

        // If x is smaller, ignore right half
        else
            r = mid - 1;
    }
}
int main()
{
    int n,h;
    scanf("%d %d",&n,&h);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int result = binarySearch(arr,n,h);
    printf("%d\n",result);
    return 0;
}