#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100005];
  scanf("%s", str);
  int len = strlen(str);

  int n;
  scanf("%d", &n);
  char to, from;
  while (n--) {
    scanf(" %c %c", &to, &from);
    for (int i = 0; i < len; ++i)
      if (str[i] == from) str[i] = to;
  }

  for (int i = 0; str[i] != '\0'; ++i)
    putchar(str[i]);
  putchar('\n');
}

