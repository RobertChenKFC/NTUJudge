#include <stdio.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int prev, cur;
    int segments = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &cur);
      if (i != 0 && prev != cur) ++segments;
      prev = cur; 
    }
    printf("%d\n", segments);
  }
}

