#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  return strcmp(*((char**)a), *((char**)b));
}

int main() {
  char buf[70][35];
  char *strings[70];
  for (int i = 0; i < 70; ++i)
    strings[i] = buf[i];
  int idx = 0;
  while (fgets(strings[idx], sizeof(buf[idx]), stdin) != NULL) ++idx;
  qsort(strings, idx, sizeof(char*), Cmp);
  for (int i = 0; i < idx; ++i)
    printf("%s", strings[i]);
}

