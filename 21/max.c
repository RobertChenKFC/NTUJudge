#include "max.h"

#include <limits.h>

int max(int arr[5][5]) {
  int m = INT_MIN;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j)
      if (arr[i][j] > m) m = arr[i][j];
  }
  return m;
}
