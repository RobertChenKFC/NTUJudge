#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  while (m >= n) {
    if (m % 100 == n) ++cnt;
    m /= 10;
  }
  printf("%d\n", cnt);
}
