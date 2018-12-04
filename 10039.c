#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100005];
  scanf("%s", str);

  char map[256];
  for (char i = 'A'; i <= 'Z'; ++i) map[i] = i;

  int n;
  scanf("%d", &n);
  char to, from;
  while (n--) {
    scanf(" %c %c", &to, &from);
    for (char i = 'A'; i <= 'Z'; ++i)
      if (map[i] == from) map[i] = to;
  }

  for (int i = 0; str[i] != '\0'; ++i)
    putchar(map[str[i]]);
  putchar('\n');
}

