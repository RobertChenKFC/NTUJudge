#include <stdio.h>

int f(int);
int g(int);
int h(int);

int f(int x) {
  int hx = h(x);
  if (x > hx) return f(x - 1) - hx;
  int gx = g(x);
  if (x < hx) return f(gx) - gx;
  return 1;
}

int h(int x) {
  if (x < 2) return -1;
  return 2 + h(x - 1) - h(x - 2);
}

int g(int x) {
  if (x <= 2) return x * x - 1;
  return 2;
}

int main() {
  int x;
  scanf("%d", &x);
  printf("%d\n", f(x));
}

