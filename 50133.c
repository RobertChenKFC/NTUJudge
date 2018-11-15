#include <stdio.h>
#include <string.h>

char totalBuf[3][100000];

void Merge(char *merged, char *str1, char *str2) {
#ifdef DEBUG
  printf("merged: %s, string 1: %s, string 2: %s\n", merged, str1, str2);
#endif

  if (*str1 == '\0' && *str2 == '\0') {
    return;
  }
  if (*str1 == '\0') {
    strcpy(merged, str2);
    return;
  }
  if (*str2 == '\0') {
    strcpy(merged, str1); 
    return;
  }
  if (strncmp(str1, str2, 3) < 0) {
    strncpy(merged, str1, 3);
    Merge(merged + 3, str1 + 3, str2);
    return;
  }
  strncpy(merged, str2, 3);
  Merge(merged + 3, str1, str2 + 3);
}

int main() {
  char *merged = totalBuf[0], *str = totalBuf[1];
  char *buf = totalBuf[2];

  scanf("%s", merged);
  while (scanf("%s", str) != EOF) {
    Merge(buf, merged, str);
    char *t = buf;
    buf = merged;
    merged = t;

    printf("%s\n", merged);
  }
}

