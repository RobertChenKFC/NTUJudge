#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int nums[16];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &nums[i]); 
  }

  int count[1 << 15] = {0};
  for (int mask = 1, end = 1 << n; mask < end; ++mask) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      if ((mask >> i) & 1) sum += nums[i];
    ++count[sum];
  }

  int sum;
  while (scanf("%d", &sum) != EOF)
    printf("%d\n", count[sum]);
}
