#include <stdio.h>
#include <stdlib.h>

int n;
int nums[10];

int inPermutation[10] = {0};
int permutation[10];
void Permutation(int cur) {
  if (cur == n) {
    for (int i = 0; i < n; ++i) {
      if (i != 0) printf(" ");
      printf("%d", permutation[i]);
    }
    printf("\n");
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (!inPermutation[i]) {
      inPermutation[i] = 1;
      permutation[cur] = nums[i];
      Permutation(cur + 1);
      inPermutation[i] = 0;
    } 
  }
}

int Cmp(const void *a, const void *b) {
  return *((int*)a) - *((int*)b);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &nums[i]);
  qsort(nums, n, sizeof(int), Cmp);
  Permutation(0);
}

