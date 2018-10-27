#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char chars[2];
  scanf("\n%c %c", &chars[0], &chars[1]);

  int cnt = n * m / 32 + ((n * m) % 32 != 0);
  unsigned int mask = 1 << 31;
  int col = 0, row = 0;
  for (int a = 0; a < cnt; ++a) {
    unsigned int x;
    scanf("%u", &x);
    for (int i = 0; i < 32; ++i) {
      printf("%c", chars[(x & mask) == 0]);
      if (++col == n) {
        printf("\n");
        if (++row == m) return 0;
        col = 0;
      }
      x <<= 1;
    }
  }
}

