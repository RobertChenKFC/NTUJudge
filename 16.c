#include <stdio.h>

int main() {
  int odd[1000], even[1000];
  int nOdd = 0, nEven = 0;
  int n;
  scanf("%d", &n);
  int x;
  while (n--) {
    scanf("%d", &x);
    if (x & 1) odd[nOdd++] = x;
    else even[nEven++] = x;
  }
  for (int i = 0; i < nOdd; ++i) {
    if (i != 0) printf(" ");
    printf("%d", odd[i]);
  }
  printf("\n");
  for (int i = 0; i < nEven; ++i) {
    if (i != 0) printf(" ");
    printf("%d", even[i]);
  }
  printf("\n");
}

