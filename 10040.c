#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  char strs[205][55];
  int lens[205];
  for (int i = 0; i < n; ++i) {
    scanf("%s", strs[i]);
    lens[i] = strlen(strs[i]);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int cnt = 0;
    char s[55];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= lens[i] - len; ++j) {
#ifdef DEBUG
        printf("Comparing %s with %s\n", strs[i] + j, s);
#endif

        if (strncmp(strs[i] + j, s, len) == 0) {
          ++cnt;
          break;
        }
      }
    }
    printf("%d\n", cnt);
  }
}

