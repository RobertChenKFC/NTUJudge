#include <stdio.h>

int main() {
  int arr[1000];
  int n;
  scanf("%d", &n);
  for (int i = n - 1; i >= 0; --i)
    scanf("%d", &arr[i]);
  for (int i = 0; i < n; ++i) {
    if (i != 0) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

