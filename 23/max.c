#include "max.h"

#include <limits.h>

int max(int *iptr[], int n) {
  int m = INT_MIN;
  for (int i = 0; i < n; ++i)
    if (*iptr[i] > m) m = *iptr[i];
  return m;
}

