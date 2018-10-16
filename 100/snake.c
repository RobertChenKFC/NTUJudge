#include "snake.h"

void snake(const int *ptr_array[100][100], int m) {
  for (int i = m * m; i > 0; --i) {
    for (int j = 0; j < i - 1; ++j) {
      int r1 = j / m, c1 = j % m;
      int r2 = (j + 1) / m, c2 = (j + 1) % m;
      if (*ptr_array[r1][c1] > *ptr_array[r2][c2]) {
        const int *t = ptr_array[r1][c1];
        ptr_array[r1][c1] = ptr_array[r2][c2];
        ptr_array[r2][c2] = t;
      }
    }
  }

  for (int i = 1; i < m; i += 2) {
    for (int j = 0, k = m - 1; j < k; ++j, --k) {
      const int *t = ptr_array[i][j];
      ptr_array[i][j] = ptr_array[i][k];
      ptr_array[i][k] = t;
    } 
  }
}

