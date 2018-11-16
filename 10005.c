#include <stdio.h>
#include <string.h>

int main() {
  char string[1005];
  while (scanf("%s", string) != EOF) {
    int len = strlen(string);
    int num = 0, printed = 1, negative = 0;
    for (int i = 0; i < len; ++i) {
      char c = string[i];
      if (c >= '0' && c <= '9') {
        num = num * 10 + string[i] - '0';
        printed = 0;
      } else if (c == '-') {
        negative = 1; 
      } else if (!printed) {
        if (negative) printf("-");
        printf("%d\n", num);
        num = 0;
        printed = 1;
        negative = 0;
      }
    }
    if (!printed) {
      if (negative) printf("-");
      printf("%d\n", num);
    }
  }
}

