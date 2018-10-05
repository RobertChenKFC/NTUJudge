#include <stdio.h>
#include <math.h>

int power(int base, int exp) {
  if (exp == 0) return 1;
  int t = power(base, exp >> 1);
  if (exp & 1) return base * t * t;
  return t * t;
}

int main() {
  int n, i;
  scanf("%d%d", &n, &i);
  printf("%d\n", power(n, i));
}

