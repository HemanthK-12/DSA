#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;
        long long maxPositions = 0;
        for (int a = 1; a <= min(x, (int)cbrt(k)); ++a) {
            if (k % a == 0) {
                long long remK = k / a;
                for (int b = 1; b <= min(y, (int)sqrt(remK)); ++b) {
                    if (remK % b == 0) {
                        int c = remK / b;
                        if (c <= z) {
                            maxPositions += (x - a + 1) * (y - b + 1) * (z - c + 1);
                        }
                    }
                }
            }
        }

        cout << maxPositions << "\n";
    }
    return 0;
}
