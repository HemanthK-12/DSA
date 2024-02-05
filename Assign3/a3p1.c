/*
Input
The first line contains an integer n (1 ≤ n ≤ 3 ∗ 103).
The second line contains a string of length n consisting of only lowercase English alphabet.
Your solution should run in O(n2) time complexity
Output
The length of the longest substring which is also a palindrome.
*/
#include <stdio.h>

int longestPalSubstr(char *str,int n)
{
    int maxLength = 1, start = 0;
    int table[n][n];

    for (int i = 0; i < n; ++i)
        for(int j=0;j<n;j++)
            table[i][j] =(i==j)?1:0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = 1;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    printf("%d\n", longestPalSubstr(str,n));
    return 0;
}