#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char board[n][m + 1];
    for (int i = 0; i < n; i++)
        scanf("%s", board[i]);
    for (int j = 0; j < m; j++) 
    {
        int empty = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = '.';
                board[empty][j] = '*';
                empty--;
            }
            else if (board[i][j] == 'o')
                empty = i - 1;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%s\n", board[i]);
    return 0;
}