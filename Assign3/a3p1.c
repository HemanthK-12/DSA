#include <stdio.h>

int isPalindrome(char* str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int longestPalindrome(char* str,int n) {
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(str, i, j))
            {
                int length = j - i + 1;
                if (length > maxLength)
                    maxLength = length;
            }
        }
    }

    return maxLength;
}

int main() {
    int n;
    scanf("%d",&n);
    char arr[n];
    scanf("%s",arr);
    printf("%d\n", longestPalindrome(arr,n));
    return 0;
}