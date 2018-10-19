#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf1[100000];
char buf2[100000];

int main() {
  char *str = buf1;
  char *buf = buf2;
  char instruction[100];
  char c;
  int len = 0;
  while (scanf("%s", instruction) != EOF) {
    if (strcmp(instruction, "insert") == 0) {
      scanf("%s %c", instruction, &c);
      if (strcmp(instruction, "left") == 0) {
#ifdef DEBUG
        printf("Insert %c from the left\n", c);
#endif

        buf[0] = c;
        strncpy(buf + 1, str, len);
        char *t = str;
        str = buf;
        buf = t;
        ++len;
      } else if (strcmp(instruction, "right") == 0) {
#ifdef DEBUG
        printf("Insert %c from the right\n", c);
#endif

        str[len++] = c;
      } else {
#ifdef DEBUG
        printf("Insert %c at %d\n", c, atoi(instruction) - 1);
#endif

        int k = atoi(instruction) - 1;
        strncpy(buf, str, k);
        buf[k] = c;
        strncpy(buf + k + 1, str + k, len - k);
        char *t = str;
        str = buf;
        buf = t;
        ++len;
      }
    } else {
      scanf("%s", instruction);
      if (strcmp(instruction, "left") == 0) {
#ifdef DEBUG
        printf("Delete from the left\n");
#endif

        strncpy(buf, str + 1, --len); 
        char *t = str;
        str = buf;
        buf = t;
      } else if (strcmp(instruction, "right") == 0) {
#ifdef DEBUG
        printf("Delete from the right\n");
#endif

        --len; 
      } else {
#ifdef DEBUG
        printf("Delete at %d\n", atoi(instruction) - 1);
#endif

        int k = atoi(instruction) - 1;
        --len;
        strncpy(buf, str, k);
        strncpy(buf + k, str + k + 1, len - k);
        char *t = str;
        str = buf;
        buf = t;
      }
    }

#ifdef DEBUG
  str[len] = '\0';
  printf("Current string: %s\n", str);
#endif
  }

  char prev = str[0];
  int curlen = 0, maxlen = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == prev) {
      ++curlen;
    } else {
      curlen = 1;
      prev = str[i];
    }
    if (curlen > maxlen) maxlen = curlen;
  }

#ifdef DEBUG
  printf("Max sequence length is %d\n", maxlen);
#endif

  prev = str[0];
  curlen = 0;
  char chars[100];
  int numChars = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == prev) {
      ++curlen;
    } else {
      curlen = 1;
      prev = str[i];
    }
    if (curlen == maxlen) chars[numChars++] = str[i];
  }

  for (int i = 0; i < numChars; ++i)
    printf("%c ", chars[i]);
  printf("%d\n", maxlen);
}

