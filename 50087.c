#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int w[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &w[i]);

  int i;
  int torque = 1;
  int a = 0, b = n - 1;
  while (torque != 0) { 
    for (i = 0; i < n; ++i) {
      torque = 0;
      for (int j = 0; j < n; ++j)
        torque += w[j] * (i - j);
      if (torque == 0)
        break;
    }

    if (torque != 0) {
      int t = w[a];
      w[a] = w[b];
      w[b] = t;
      ++a, --b;
    }
  }

  for (int j = 0; j < n; ++j) {
    if (j != 0)
      printf(" ");
    if (i == j)
      printf("v");
    else
      printf("%d", w[j]);
  }
  printf("\n");
}
