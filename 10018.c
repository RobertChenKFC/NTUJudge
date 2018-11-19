#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[100005] = {0};
  while (n--) {
    int x;
    scanf("%d", &x);
    if (arr[x]) {
      printf("%d\n", x);
      break;
    }
    arr[x] = 1;
  }
}

