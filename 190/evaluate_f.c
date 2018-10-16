#include "evaluate_f.h"

#include "limits.h"

int evaluate_f(int *iptr[], int n, int *index) {
  int max = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int cur = 4 * iptr[i][0] - 6 * iptr[i][1];
    if (cur > max) {
      max = cur;
      *index = i;
    }
  }
  return max;
}

