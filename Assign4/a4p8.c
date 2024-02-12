#include <stdio.h>
#include <string.h>

int c=0;

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int countConsecutive(char *str, int n) {
    int count = 1, maxCount = 1;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 1;
        }
    }
    return maxCount;
}
int countK(char *str, int n) {
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        if (str[i] == 'K') {
            count++;
        }
    }
    return count;
}

void permute(char *str, int l, int r, int a, int b) {
    int i;
    if (l == r && str[0] == 'K' && countConsecutive(str, r + 1) <= b && countK(str,r+1)==a/2) {
        c++;
        if(c % 21 != 0) printf("%s   ", str);
        else printf("\n");
    } else {
        for (i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r, a, b);
            swap((str + l), (str + i)); 
        }
    }
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    char str[n];
    for(int i = 0; i < a; i++)
        str[i] = 'K';
    for(int i = a; i < n; i++)
        str[i] = 'O';
    permute(str, 0, n - 1, a, b);
    return 0;
}