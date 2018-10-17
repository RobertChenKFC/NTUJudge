#include <stdio.h>
#include <string.h>

char s[200000];
char buf[200000];

int main() {
  while (fgets(buf, sizeof(s), stdin) != NULL)
    strcat(s, buf);
  int len = strlen(s);
  int end = 0;
  for (int i = len - 1; i >= 0; --i) {
    if (i != '\n' && i != ' ') {
      end = i;
      break;
    }
  }

  int oneLeft = len - 2, twoLeft = len - 3;
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] == '.' && (
        (i <= twoLeft && s[i + 1] == ' ' && s[i + 2] == ' ') ||
        (i <= oneLeft && (s[i + 1] == '\n' || s[i + 1] == '\0')) ||
        (i == end)))
      ++count;
  }

  printf("%d\n", count);
}

