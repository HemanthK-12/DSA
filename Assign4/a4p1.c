#include <stdio.h>

char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *thousands[] = {"", "thousand", "million", "billion"};

void printNumber(long long num, int idx) {
    if (num == 0)
        return;
    printNumber(num / 1000, idx + 1);
    int rem = num % 1000;
    if (rem / 100 > 0) {
        printf("%s hundred ", ones[rem / 100]);
    }
    rem %= 100;
    if (rem >= 20) {
        printf("%s ", tens[rem / 10]);
        rem %= 10;
    } else if (rem >= 10) {
        printf("%s ", teens[rem % 10]);
        rem = 0;
    }
    if (rem > 0)
        printf("%s ", ones[rem]);
    if (idx > 0)
        printf("%s ", thousands[idx]);
}

int main() {
    long long n;
    scanf("%lld", &n);
    if(n==0)
    printf("zero");
    else
    printNumber(n, 0);
    printf("\n");
    return 0;
}