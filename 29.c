#include <stdio.h>
#include <string.h>

int C[24][24];
int Choose(int n, int k) {
  if (k == -1 || k > n) return 0;
  if (C[n][k] != -1) return C[n][k];
  C[n][k] = Choose(n - 1, k - 1) + Choose(n - 1, k);
  return C[n][k];
}

int main() {
  memset(C, -1, sizeof(C));
  C[0][0] = 1;
  int r, c;
  scanf("%d%d", &r, &c);
  printf("%d\n", Choose(r + c - 2, r - 1));
}

