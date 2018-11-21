#include <stdio.h>
#include <string.h>

int main() {
  int type;
  scanf("%d", &type);
  if (type == 0) {
    char s[100005]; 
    scanf("%s", s);
    unsigned long long x = 0;
    int len = strlen(s);
    int shift = 56;
    for (int i = 0; i <= len; ++i) {
      if (shift == -8) {
        printf("%llu\n", x); 
        x = 0;
        shift = 56;
      } 
      x |= (unsigned long long)s[i] << shift;
      shift -= 8;
    }
    if (shift != 56) printf("%llu\n", x);
  } else if (type == 1) {
    int n;
    scanf("%d", &n);
    while (n--) {
      unsigned long long x;
      scanf("%llu", &x);
      for (int shift = 56; shift != -8; shift -= 8) {
        char c = x >> shift;
        if (c == '\0') {
          putchar('\n');
          break;
        }
        putchar(c);
      }
    }
  }
}

