#include <stdio.h>

int main() {
  int mat[100][100];
  int r, c;
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      scanf("%d", &mat[i][j]);
  }
  
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if ((i == 0 || mat[i - 1][j] < mat[i][j]) &&
          (i == r - 1 || mat[i + 1][j] < mat[i][j]) &&
          (j == 0 || mat[i][j - 1] < mat[i][j]) &&
          (j == c - 1 || mat[i][j + 1] < mat[i][j]))
        printf("%d\n", mat[i][j]);
    }
  }
}

