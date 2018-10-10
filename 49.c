#include <stdio.h>
#include <limits.h>
#include <string.h>

int sum[1000];
int max[1000];
int min[1000];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(sum, 0, sizeof(int) * m);
  for (int i = 0; i < m; ++i) {
    max[i] = INT_MIN;
    min[i] = INT_MAX;
  }
  int x;
  while (n--) {
    scanf("%d", &x);
    int r = x % m;
    sum[r] += x;
    if (x > max[r]) max[r] = x;
    if (x < min[r]) min[r] = x;
  }

  for (int i = 0; i < m; ++i)
    printf("%d %d %d\n", sum[i], max[i], min[i]);
}

