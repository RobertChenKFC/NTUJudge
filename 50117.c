#include <stdio.h>

int main() {
  int div;
  scanf("%d", &div);
  int cur = 0;
  int x;
  int first = 1;
  while (scanf("%d", &x) != EOF) {
    cur = cur * 10 + x;
    if (!first || cur >= div) {
      first = 0;
      printf("%d\n", cur / div);
      cur %= div;
    }
  }
  if (first) printf("0\n");
}

