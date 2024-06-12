#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Attack {
    long long damage;
    long long cooldown;
    long long nextAvailableTurn;
};

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long h;
        long long n;
        cin >> h >> n;

        vector<long long> damages(n);
        vector<long long> cooldowns(n);

        for (long long i = 0; i < n; ++i) {
            cin >> damages[i];
        }
        for (long long i = 0; i < n; ++i) {
            cin >> cooldowns[i];
        }

        // Priority queue to keep track of next available turn for each attack
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        vector<Attack> attacks(n);
        for (long long i = 0; i < n; ++i) {
            attacks[i] = {damages[i], cooldowns[i], 1};
            pq.push(1);
        }

        long long currentTurn = 1;
        long long totalDamage;
        while (h > 0) {
            totalDamage = 0;
            while (!pq.empty() && pq.top() == currentTurn) {
                pq.pop();
            }
            for (long long i = 0; i < n; ++i) {
                if (attacks[i].nextAvailableTurn <= currentTurn) {
                    totalDamage += attacks[i].damage;
                    attacks[i].nextAvailableTurn = currentTurn + attacks[i].cooldown;
                    pq.push(attacks[i].nextAvailableTurn);
                }
            }
            h -= totalDamage;
            if (totalDamage == 0) {
                currentTurn = pq.top();
            } else {
                currentTurn++;
            }
        }

        cout << currentTurn - 1 << endl;
    }

    return 0;
}
