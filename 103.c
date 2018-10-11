#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  double mat[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%lf", &mat[i][j]);  
  }

  double vec[n];
  for (int i = 0; i < n; ++i)
    scanf("%lf", &vec[i]);  

  double x[n];
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j > i; --j)
      vec[i] -= mat[i][j] * x[j];
    x[i] = vec[i] / mat[i][i];
  }

  for (int i = 0; i < n; ++i)
    printf("%lf\n", x[i]);
}

