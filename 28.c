#include <stdio.h>

int Sum(int n) {
  if (n == 1) return 1;
  return n * n + Sum(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", Sum(n));
}

