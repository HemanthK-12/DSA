/*
Input
The first line contains an integer n (1 ≤ n ≤ 3 ∗ 103).
The second line contains a string of length n consisting of only lowercase English alphabet.
Your solution should run in O(n2) time complexity
Output
The length of the longest substring which is also a palindrome.
*/
#include <stdio.h>

int max_palindrome(char s[],int n){
    int start=0;
    int end=1;
    for(int i=1;i<n;i++){
        int l=i-1;
        int h=i;
        while(l>=0 && h<n && s[h]==s[l]){
            if(h-l+1>end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
    }
    for(int i=1;i<n;i++){
        int l=i-1;
        int h=i+1;
        while(l>=0 && h<n &&s[h]==s[l]){
            if(h-l+1>end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
    }
    return end;
}

int main(){
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    printf("%d",max_palindrome(s,n));

}