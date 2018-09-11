#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  int x = 0, y = 0;
  printf("0\n0\n");
  int i;
  while (scanf("%d", &i) != EOF) {
    switch (i % 5) {
    case 1:
      if (x + i < n) {
        x += i;
        printf("%d\n%d\n", x, y);
      }
      break;
    case 2:
      if (x - i >= 0) {
        x -= i;
        printf("%d\n%d\n", x, y);
      }
      break;
    case 3:
      if (y + i < m) {
        y += i;
        printf("%d\n%d\n", x, y);
      }
      break;
    case 4:
      if (y - i >= 0) {
        y -= i;
        printf("%d\n%d\n", x, y);
      }
      break;
    } 
  }
}
