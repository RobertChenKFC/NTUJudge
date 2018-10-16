#include "fill_array.h"

#include <string.h>
#include <stdio.h>

void fill_array(int *ptr[], int n) {
  int *begin = ptr[0];
  int *end = ptr[n - 1] + 1;
  int total = (int)(end - begin);
  int buf[total];
  char pointed[total];

#ifdef DEBUG
  printf("total: %d\n", total);
#endif
  memset(pointed, 0, total);

  for (int i = 0; i < n; ++i) {
    int idx = (int)(ptr[i] - begin);
    buf[idx] = i;
    pointed[idx] = 1;
#ifdef DEBUG
    printf("%d: %d\n", i, idx);
#endif
  }

  for (int i = 0; i < total; ++i) {
    if (pointed[i]) {
      *(begin + i) = buf[i];
    } else {
      int sum = 0;
      for (int j = i - 1; j >= 0; --j) {
        if (pointed[j]) {
          sum += buf[j];
          break;
        }
      }
      for (int j = i + 1; j < total; ++j) {
        if (pointed[j]) {
          sum += buf[j];
          break;
        }
      }
      *(begin + i) = sum;
    }
  }
}

