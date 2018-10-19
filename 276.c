#include <stdio.h>
#include <string.h>

int main() {
  char abbv[128];
  char s[128];
  int cur = 0;
  char diff = 'A' - 'a';
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    int last = 0;
    if (s[len - 1] == '.') {
      s[len - 1] = '\0'; 
      last = 1;
    }
    if (strcmp(s, "of") != 0 && strcmp(s, "the") != 0 && strcmp(s, "and") != 0 && strcmp(s, "at") != 0)
      abbv[cur++] = s[0] + diff;
    if (last) {
      abbv[cur] = '\0';
      printf("%s\n", abbv);
      cur = 0;
    } 
  }
}

