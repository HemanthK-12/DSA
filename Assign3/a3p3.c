#include <stdio.h>
//This uses two pointer approach
void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char* s) {
    char* word_begin = s;
    char* temp = s;

    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        } else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    char s[n];
    scanf(" %[^\n]", s);
    reverseWords(s);
    printf("%s", s);
    return 0;
}