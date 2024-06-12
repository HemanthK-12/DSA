#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0, maxElement = 0;
        int goodPrefixes = 0;
        map<long long, int> prefixSums;
        prefixSums[0] = 1;

        for(int i = 0; i < n; i++) {
            if(prefixSums[sum - maxElement] > 0 && sum - maxElement >= 0) {
                goodPrefixes++;
            }
            sum += a[i];
            maxElement = max(maxElement, a[i]);
            prefixSums[sum]++;
        }

        cout << goodPrefixes << "\n";
    }

    return 0;
}