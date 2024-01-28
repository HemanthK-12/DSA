/*
You are given an array with N integers, such that there exists an i:
•a1 < a2 < . . . < ai
•ai > ai+1 > . . . > an
You have to help Nom find the index of the peak. Assume 1-based indexing.

Input
The first line contains a positive integer N (1 ≤N ≤106).
The second line contains N integers a1, a2, . . . , aN (−109 ≤ai ≤109).
Output
A single positive integer indicating the peak index of the mountain.
Your solution should run in O(logN) time complexity
*/
#include<stdio.h>

int findPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int peakIndex = findPeak(arr, n);
    printf("%d", peakIndex+1);

    return 0;
}