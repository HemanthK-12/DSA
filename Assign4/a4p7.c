#include <stdio.h>
#include <string.h>


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    char a[100000];
    char b[100000];
    scanf("%[^\n]",a);
    scanf(" %[^\n]",b);
    char lcm[200000];
    int lenA = strlen(a), lenB = strlen(b), lenLCM = lenA * lenB / gcd(lenA, lenB);
    for (int i = 0; i < lenLCM; i++)
        lcm[i] = (i < lenA) ? a[i % lenA] : b[i % lenB];
    lcm[lenLCM] = '\0';
    for (int i = 0; i < lenLCM; i++)
    {
        if (lcm[i] != lcm[i % lenA] || lcm[i] != lcm[i % lenB])
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n", lcm);
    return 0;
}