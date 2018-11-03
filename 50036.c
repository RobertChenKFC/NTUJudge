#include <stdio.h>

int main() {
  int k, n, m;
  int nums[25];
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &nums[i]);
  int ways = 0;
  for (int mask = 1, to = 1 << n; mask < to; ++mask) {
    int cur = mask;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (cur & 1) {
        sum += nums[i];
        ++cnt;
      }
      cur >>= 1;
    }
    if (cnt >= k && sum <= m) ++ways;
  }
  printf("%d\n", ways);
}

