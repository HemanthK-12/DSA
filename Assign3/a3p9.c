#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

long long productOfNonPrimes(int arr[], int n)
{
    long long modulus=1000000007;
    long long product = 1;
    int hasNonPrime = 0;
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i])) {
            product = (product * arr[i]) % modulus;
            hasNonPrime = 1;
        }
    }
    return hasNonPrime ? product : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long product = productOfNonPrimes(arr, n);
    printf("%lld", product);

    return 0;
} 