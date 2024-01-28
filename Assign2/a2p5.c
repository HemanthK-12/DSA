#include <stdio.h>

int binarySearch(int matrix[1000][1000], int n, int k) {
    int row = 0;
    int col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == k) {
            return 1;
        } else if (matrix[row][col] < k) {
            row++;
        } else {
            col--;
        }
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int matrix[1000][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (binarySearch(matrix, n, k)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}