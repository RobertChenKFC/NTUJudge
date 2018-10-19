#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char buf1[80], buf2[80];
    char *s1 = buf1, *s2 = buf2;
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 < len2) {
      char *t = s1;
      s1 = s2;
      s2 = t;
      int tlen = len1;
      len1 = len2;
      len2 = tlen;
    }

#ifdef DEBUG
    printf("%s %s\n", s1, s2);
#endif

    if (len1 == len2) {
      if (strcmp(s1, s2) == 0) printf("yes\n");
      else {
        for (int i = 0; i < len1; ++i) {
          for (int j = i + 1; j < len2; ++j) {
            char t = s1[i];
            s1[i] = s1[j];
            s1[j] = t;
            if (strcmp(s1, s2) == 0) {
              printf("yes\n");
              goto NEXT;
            }
            t = s1[i];
            s1[i] = s1[j];
            s1[j] = t;
          } 
        }
        printf("no\n");
      }
    } else if (len1 - len2 == 1) {
      for (int i = 0; i < len1; ++i) {
        int same = 1;
        for (int j = 0, k = 0; k < len2; ++j, ++k) {
          if (i == j) ++j;
          if (s1[j] != s2[k]) {
            same = 0;
            break;
          }
        }
        if (same) {
          printf("yes\n");
          goto NEXT;
        }
      } 
      printf("no\n");
    } else {
      printf("no\n"); 
    }
    NEXT:
    continue;
  }
}

