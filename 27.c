#include <stdio.h>

int main() {
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  int sa = a - (e << 1), sb = b - (e << 1), sc = c - (e << 1);
  printf("%d\n%d\n",
         (a * b + b * c + c * a + ((d * (sa + sb + sc)) << 2)) << 1,
         (a * b * c - (d * (sa * sb + sb * sc + sc * sa) << 1)));
}

