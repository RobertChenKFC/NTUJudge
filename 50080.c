#include <stdio.h>
#include <limits.h>

int main() {
  int n;
  int x;
  while (1) {
    if (scanf("%d", &n) == EOF)
      break;
    int max = INT_MIN, min = INT_MAX;
    while (n--) {
      if (scanf("%d", &x) == EOF)
        break;
      if (max < x) max = x;
      if (min > x) min = x;
    }
    if (n != -1)
      printf("%d\n", min);
    else
      printf("%d\n", max);
  }
}
