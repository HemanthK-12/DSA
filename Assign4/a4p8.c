#include <stdio.h>

int main() {
    
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    
    int arr[b + 1];
    for (int i = 0; i < b + 1; i++) {
        arr[i] = 0;
    }
    
    int i = 0;
    while (a) {
        arr[i % (b + 1)]++;
        a--;    
        i++;
    }
    
    char str[n + 1];
    
    int start = 0;
    int numberofOs = b;
    
    for (int j = 0; j < b + 1; j++) {
        while (arr[j]) {
            str[start] = 'K';
            arr[j]--;
            start++;
        }
        
        if (numberofOs) {
            str[start] = 'O';
            start++;
            numberofOs--;
        }
    }
    
    printf("%s", str);
    
    return 0;
}