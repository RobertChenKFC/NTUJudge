#include <stdlib.h>
#include <stdio.h>

int Cmp(const void *pa, const void *pb) {
  long long a = *((long long *)pa), b = *((long long *)pb);
  int numA = 0, numB = 0;
  for (int i = 0; i < 64; ++i) {
    if ((a >> i) & 1) ++numA;
    if ((b >> i) & 1) ++numB;
  }
  if (numA == numB) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
  }
  return numA - numB;
}

int main() {
  long long nums[1005];
  int idx = 0;
  long long num;
  while (scanf("%lld", &num) != EOF)
    nums[idx++] = num; 
  qsort(nums, idx, sizeof(long long), Cmp);
  for (int i = 0; i < idx; ++i)
    printf("%lld\n", nums[i]);
}

