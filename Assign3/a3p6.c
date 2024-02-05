/*
Input
The first line contains three integers n, k and x (1 ≤ k ≤ n ≤ 105, 1 ≤ x ≤ 109).
The second line contains n integers which represent the cursed energies of the cursed spirits in
sequence a (−109 ≤ ai ≤ 109).
Your solution should run in O(n) time complexity.
Output
number of groups of k numbers whose average>=x.
*/
#include<stdio.h>
//This uses sliding window
int main() {
    int n, k, x, c = 0;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < k; i++)
        sum += a[i];

    for(int i = k; i <= n; i++)
    {
        if(sum >= x * k)
            c++;    
        if(i < n)
            sum = sum - a[i - k] + a[i];
    }
    printf("%d", c);
    return 0;
}