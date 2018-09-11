#include <stdio.h>

int n(int a, int b) {
  if (a > b)
    return 0;
  return (a + b) * (b - a + 1) / 2;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n%d\n", (a + b) * (b - a + 1) / 2,
                     (b - a - 1) * 2 + a + b);

}
