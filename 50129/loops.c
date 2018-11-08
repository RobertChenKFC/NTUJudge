#include "loops.h"
 
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LEN ans[0]
#define MIN_LEN ans[1]
#define MAX ans[2]
#define MIN ans[3]
 
void loops(int N, int *A, int *B[], int ans[4]) {
  int *checked = malloc(N * sizeof(int));
  memset(checked, 0, N * sizeof(int));
  MAX_LEN = MAX = INT_MIN;
  MIN_LEN = MIN = INT_MAX;
  for (int i = 0, *j = &A[0]; i < N; ++i, ++j) {
    if (checked[j - A]) continue;
    int *start = j, *cur = j;
    int len = 0;
    int curMin = INT_MAX;
    int curMax = INT_MIN;
    do {
#ifdef DEBUG
      printf("Checking %d\n", *cur);
#endif
      ++len;
      checked[cur - A] = 1;
      if (*cur < curMin) curMin = *cur;
      if (*cur > curMax) curMax = *cur;
      cur = B[cur - A];
    } while (cur != start);
 
#ifdef DEBUG
    printf("Loop length: %d, min: %d, max: %d\n", len, curMin, curMax);
#endif
 
    if (len > MAX_LEN || (len == MAX_LEN && curMax > MAX)) {
      MAX_LEN = len;
      MAX = curMax;
    }
    if (len < MIN_LEN || (len == MIN_LEN && curMin < MIN)) {
      MIN_LEN = len;
      MIN = curMin;
    }
  }
  free(checked);
}
