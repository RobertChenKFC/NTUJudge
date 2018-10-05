#include <stdio.h>

int Cross(int x1, int y1, int x2, int y2) {
  return x1 * y2 - x2 * y1;
}

int main() {
  int a, b, c, d, e, f, g, h;
  scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
  printf("%d\n", 
         Cross(a, b, c, d) > 0 &&
         Cross(c, d, e, f) > 0 &&
         Cross(e, f, g, h) > 0 &&
         Cross(g, h, a, b) > 0);
}

