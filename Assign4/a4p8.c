#include <stdio.h>

int main()
{
    int n, NumK, NumO;
    scanf("%d %d %d", &n, &NumK, &NumO);
    char String[n + 1];
    String[n] = '\0'; // Corrected the null terminator
    int Dist = NumK / (NumO + 1);
    int excess = NumK % (NumO + 1);
    int i = 0;
    int D = Dist;
    while (excess != 0)
    {
        while (D--)
        {
            String[i++] = 'K';
            NumK--;
        }
        String[i++]='K';
        String[i++] = 'O';
        NumO--;
        D = Dist;
        excess--;
    }
    while (i < n)
    {
        while (D--)
        {
            String[i++] = 'K';
            NumK--;
        }
        if (i < n)
        {
            String[i++] = 'O';
            NumO--;
        }
        D = Dist;
    }
    printf("%s\n", String);
    return 0;
}

