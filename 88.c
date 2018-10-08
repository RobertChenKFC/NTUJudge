#include <stdio.h>

int main() {
  char x[5], y[5];
  scanf("%s%s", x, y);
  int a = 0, b = 0;
  for (int i = 0; i < 4; ++i)
    if (x[i] == y[i]) ++a;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      if (x[i] == y[j]) ++b; 
  }
  printf("%dA%dB\n", a, b - a);
}
