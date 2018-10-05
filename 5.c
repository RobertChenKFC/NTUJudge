#include <stdio.h>

int main() {
  int h, w, d;
  scanf("%d%d%d", &h, &w, &d);
  printf("%d\n%d\n", (h * w + w * d + d * h) << 1, h * w * d);
}

