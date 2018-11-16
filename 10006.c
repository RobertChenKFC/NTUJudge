#include <stdio.h>

int main() {
  int sum = 0;
  int num;
  while (scanf("%d", &num) != EOF) sum += num;
  printf("%d\n", sum);
}

