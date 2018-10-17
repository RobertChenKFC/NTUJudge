#include <stdio.h>
#include <string.h>

int main() {
  char s[100];
  scanf("%s", s);

  int count[256] = {0};
  char diff = 'A' - 'a';
  for (int i = 0, len = strlen(s); i < len; ++i) {
    if (s[i] >= 'a' && s[i] <= 'z') s[i] += diff;
    if (s[i] >= 'A' && s[i] <= 'Z') ++count[s[i]];
  }

  for (char i = 'A'; i <= 'Z'; ++i)
    printf("%d\n", count[i]);
}

