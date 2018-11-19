#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i = 0, j = n - 1;
  int x;
  int arr[100005];
  for (int a = 0; a < n; ++a) {
    scanf("%d", &x);
    if (x == 0) arr[j--] = x;
    else arr[i++] = x;
  }
  for (int a = 0; a < n; ++a) {
    if (a != 0) printf(" ");
    printf("%d", arr[a]);
  }
  printf("\n");
}

