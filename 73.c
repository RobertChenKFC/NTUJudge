#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int x; 
  int cnt[3] = {0};
  while (n--) {
    scanf("%d", &x);
    ++cnt[x % 3];
  }
  printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
}

