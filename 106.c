#include <stdio.h>
#include <string.h>

int main() {
  char num[1000];
  while (scanf("%s", num) != EOF) {
    if (num[0] == '-' && num[1] == '1') return 0; 
    int div[4] = {0};
    int len = strlen(num);

    div[0] = (num[len - 1] - '0') % 2 == 0;
    div[2] = (num[len - 1] - '0') % 5 == 0;
    int sum = 0;
    int diff = 0;
    for (int i = 0; i < len; ++i) {
      int dig = num[i] - '0';
      sum += dig;
      if (i % 2 == 0) diff += dig;
      else diff -= dig;
    }
    div[1] = sum % 3 == 0;
    if (diff < 0) diff = -diff;
    div[3] = diff % 11 == 0;

    for (int i = 0; i < 4; ++i) {
      if (i != 0) printf(" ");
      if (div[i]) printf("yes");
      else printf("no");
    }
    printf("\n");
  }
}

