#include <stdio.h>
#include <string.h>
 
int mat[1000][1000];
 
int main() {
  int n, k, x, y;
  scanf("%d%d%d%d", &n, &k, &x, &y);
 
  memset(mat, -1, sizeof(mat));
 
  while (k != 1) {
    x = (x + 1) % n;
    y = (y == 0) ? (n - 1) : (y - 1);
    --k;
  }
  int sq = n * n;
  for (int i = 1; i <= sq; ++i) {
    mat[x][y] = i;
 
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != 0) printf(" ");
        printf("%d", mat[i][j]);
      } 
      printf("\n");
    }
    printf("\n");
#endif
 
    int newx = (x == 0) ? (n - 1) : (x - 1);
    int newy = (y + 1) % n;
    if (mat[newx][newy] != -1) {
      x = (x + 1) % n;
    } else {
      x = newx;
      y = newy;
    }
  }
 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j != 0) printf(" ");
      printf("%d", mat[i][j]);
    } 
    printf("\n");
  }
}
