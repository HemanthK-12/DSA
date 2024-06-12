#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;

// Function to compute the sum of digits of a number
ll digitSum(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number satisfies the condition
bool satisfiesCondition(ll n, ll k) {
    ll dn = digitSum(n);
    ll dkn = digitSum(k * n);
    return (dkn == k * dn);
}

// Function to compute the count of numbers satisfying the condition in the given range
ll countValidNumbers(ll l, ll r, ll k) {
    ll lower = 1;
    for (int i = 0; i < l; i++) lower *= 10;
    ll upper = 1;
    for (int i = 0; i < r; i++) upper *= 10;

    ll count = 0;
    for (ll n = lower; n < upper; n++) {
        if (satisfiesCondition(n, k)) {
            count = (count + 1) % MOD;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<ll> results;

    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        results.push_back(countValidNumbers(l, r, k));
    }

    for (ll result : results) {
        cout << result << endl;
    }

    return 0;
}
