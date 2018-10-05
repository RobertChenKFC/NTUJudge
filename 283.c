#include <stdio.h>

int main() {
  int s, f, t;
  scanf("%d%d%d", &s, &f, &t);
  int c = s - t;
  int b = ((f - (c << 3)) >> 1) - t;
  int a = t - b;
  printf("%d\n%d\n%d\n", a, b, c);
}

