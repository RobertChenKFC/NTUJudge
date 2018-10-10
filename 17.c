#include <stdio.h>

int main() {
  int mat[100][100]; 
  int r, c;
  scanf("%d%d", &r, &c);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      scanf("%d", &mat[i][j]);
  }

  for (int j = 0; j < c; ++j) {
    int sum = 0;
    for (int i = 0; i < r; ++i)
      sum += mat[i][j];
    printf("%d\n", sum / r);
  }
}

