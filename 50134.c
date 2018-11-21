#include <stdio.h>
 
int main() {
  int type;
  scanf("%d", &type);
  if (type == 0) {
    char pattern[5]; 
    unsigned int l;
    unsigned short s;
    char c[3];
    while (scanf("%s%u%hu%s", pattern, &l, &s, c) != EOF) {
#ifdef DEBUG
      printf("input: %s %u %hu %s\n", pattern, l, s, c);
#endif
 
      unsigned long long x = 0;
      int shift = 0;
      int charIdx = 1;
      for (int i = 3; i >= 0; --i) {
        switch (pattern[i]) {
          case 'C':
            x |= ((unsigned long long)c[charIdx--]) << shift;
            shift += 8;
            break;
          case 'S':
            x |= ((unsigned long long)s) << shift;
            shift += 16;
            break;
          case 'L':
            x |= ((unsigned long long)l) << shift;
            shift += 32;
            break;
        }
      }
      printf("%llu\n", x);
    }
  } else if (type == 1) {
    char pattern[10];
    unsigned long long x;
    while (scanf("%s%llu", pattern, &x) != EOF) {
      unsigned int l;
      unsigned short s;
      char c[3] = {0};
      int shift = 0;
      int charIdx = 1;
      for (int i = 3; i >= 0; --i) {
        switch (pattern[i]) {
          case 'C':
            c[charIdx--] = x >> shift;
            shift += 8;
            break;
          case 'S':
            s = x >> shift;
            shift += 16;
            break;
          case 'L':
            l = x >> shift;
            shift += 32;
            break;
        } 
      }
      printf("%u %hu %s\n", l, s, c);
    }
  }
}

