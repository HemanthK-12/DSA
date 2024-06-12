#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
            cin >> grid[i];
        int rowmin = n, rowmax = -1, colmin = m, colmax = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#') {
                    if (i < rowmin) rowmin = i;
                    if (i > rowmax) rowmax = i;
                    if (j < colmin) colmin = j;
                    if (j > colmax) colmax = j;
                }
            }
        }
        int centerRow = (rowmin + rowmax) / 2 + 1;
        int centerCol = (colmin + colmax) / 2 + 1;

        cout << centerRow << " " << centerCol << endl;
    }

    return 0;
}
