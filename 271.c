#include <stdio.h>

int main() {
  int f[100], g[100];
  int p[200] = {0};
  int n;
  scanf("%d", &n);
  for (int i = n - 1; i >= 0; --i)
    scanf("%d", &f[i]); 
  int m;
  scanf("%d", &m);
  for (int i = m - 1; i >= 0; --i)
    scanf("%d", &g[i]); 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) 
      p[i + j] += f[i] * g[j]; 
  }
  int started = 0;
  for (int i = m + n; i >= 0; --i) {
    if (started) printf(" %d", p[i]);
    else if (p[i] != 0) {
      started = 1;
      printf("%d", p[i]);
    }
  }
  printf("\n");
}

