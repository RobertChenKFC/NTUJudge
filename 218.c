#include <stdio.h>

int c[16][16];
int C(int n, int k) {
  if (n < 0 || k < 0) return 0;
  if (c[n][k] != -1) return c[n][k];
  c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
  return c[n][k];
}

int main() {
  for (int i = 0; i <= 15; ++i)
    for (int j = 0; j <= 15; ++j) c[i][j] = -1;
  c[0][0] = 1;
  
  int n, m;
  scanf("%d%d", &n, &m);
  int sum = 0;
  for (int i = 0; i <= m; ++i)
    sum += C(n, i);
  printf("%d\n", sum);
}
