#include<stdio.h>

double squareRoot(int n) {
    double low = 0, high = n, mid;
    while (high - low > 1e-7) {
        mid = low + (high - low) / 2;
        if(mid * mid <= n)
            low = mid;
        else
            high = mid;
    }
    return mid;
}

int main() {
    int n;
    scanf("%d", &n);
    if(n==1)
    {
        printf("1.000000");
        return 0;
    }
    char str[50];
    // double result = squareRoot(n);
    // result = (long)(result * 1e6) / 1e6;
    // printf("%.6lf", result);
    sprintf(str, "%.7lf",squareRoot(n));
    for(int i=0;i<6;i++)
    {
        if(str[i]=='.')
        {
            printf(".");
            for(int j=0;j<6;j++)
            {
                printf("%c",str[i+j+1]);
            }
            break;
        }
        printf("%c",str[i]);
    }    
    return 0;
}