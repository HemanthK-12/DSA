/*
Input
The first line contains an integer n (1 ≤ n ≤ 105).
The second line contains a string of length n consisting of only lowercase English alphabet.
Your solution should run in O(n) time complexity.
Output
The maximum number of consecutive alphabets without repetition.
*/
#include <stdio.h>

int longestUniqueSubstr(char* str,int n)
{
    int cur_len = 1; // length of current part of string
    int max_len = 1; // result
    int prev_index;  // previous index
    int visited[3000];

    for (int i = 0; i < 3000; i++)
        visited[i] = -1;
    
    visited[str[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        prev_index = visited[str[i]];

        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;
        else
        {
            if (cur_len > max_len)
                max_len = cur_len;

            cur_len = i - prev_index;
        }

        visited[str[i]] = i;
    }

    if (cur_len > max_len)
        max_len = cur_len;

    return max_len;
}

int main() {
    int n;
    scanf("%d",&n);
    char str[n];
    scanf("%s", str);
    printf("%d",longestUniqueSubstr(str,n));
    return 0;
}