#include <stdio.h>
#include <string.h>

int main() {
  char s[128];
  char buf[129];
  buf[0] = '\0';
  char *fused = buf + 1;
  scanf("%s", fused);
  int len = strlen(fused);
  while (scanf("%s", s) != EOF) {
#ifdef DEBUG
    printf("Current string: %s\n", fused);
    printf("Fusing %s\n", s);
#endif
    
    int slen = strlen(s);
    char *to, *from = s;
    int complen;
    if (len < slen) {
      to = fused;
      complen = len;
    } else {
      to = fused + len - slen;
      complen = slen;
    }
    while (complen != 0 && strncmp(to, from, complen) != 0) {
#ifdef DEBUG
      printf("Comparing %s and %s\n", to, from);
#endif
      --complen;
      ++to;
    }
#ifdef DEBUG
      printf("Fusing length %d\n", slen - complen);
#endif
    strncpy(fused + len, from + complen, slen - complen);
    len += slen - complen;
    fused[len] = '\0';
  }
  printf("%s\n", fused);
}

