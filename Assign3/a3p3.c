/*
Input
The first line contains an integer n (1 ≤ n ≤ 105).
The second line contains a string of length n consisting of only lowercase English alphabet and
whitespace.
Your solution should run in O(n) time complexity.
Output
A string of length n ,where every word is reversed.
*/
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