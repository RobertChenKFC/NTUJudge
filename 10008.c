#include <stdio.h>

int main() {
  int n;
  int vals[] = {1000, 500, 100, 50, 10, 5, 1};
  int types = 7;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < types; ++i) {
      if (i != 0) printf(" ");
      printf("%d", n / vals[i]);
      n %= vals[i];
    } 
    printf("\n");
  }
}

