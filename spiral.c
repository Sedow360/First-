#include <stdio.h>

#define SIZE 10

int main() {
    char matrix[SIZE][SIZE] = {0};
    int i, j, k = 0, l = 0;
    int m = SIZE, n = SIZE;

    while (k < m && l < n) {
        // Fill the first row from the remaining rows with '*'
        for (i = l; i < n; ++i) {
            matrix[k][i] = '*';
        }
        k++;

        // Fill the last column from the remaining columns with '*'
        for (i = k; i < m; ++i) {
            matrix[i][n - 1] = '*';
        }
        n--;

        // Fill the last row from the remaining rows with '*'
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                matrix[m - 1][i] = '*';
            }
            m--;
        }

        // Fill the first column from the remaining columns with '*'
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                matrix[i][l] = '*';
            }
            l++;
        }
    }

    // Print the spiral matrix with '*' and spaces
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == '*') {
                printf("* ");
            } else {
                printf("  "); // Two spaces to keep the alignment
            }
        }
        printf("\n");
    }

    return 0;
}