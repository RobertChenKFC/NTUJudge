#include <stdio.h>
#include <limits.h>

int main() {
  int x, y;
  int minx = INT_MAX, miny = INT_MAX;
  int maxx = INT_MIN, maxy = INT_MIN;
  while (scanf("%d%d", &x, &y) != EOF) {
    if (x < minx) minx = x;
    if (x > maxx) maxx = x;
    if (y < miny) miny = y;
    if (y > maxy) maxy = y;
  }
  printf("%d\n", (maxx - minx) * (maxy - miny));
}

