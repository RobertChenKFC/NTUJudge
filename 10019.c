#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char s[100];
  while (fgets(s, sizeof(s), stdin) != NULL) {
    char *out = s;
    while (isspace(*out)) ++out;
    char *end = s + strlen(s) - 2;
    while (isspace(*end)) --end;
    *(end + 1) = '\0';

    printf("%s\n", out);
  }
}

