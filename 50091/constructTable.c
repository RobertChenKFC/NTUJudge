#include "constructTable.h"

#include <stdio.h>

int **firstLevel[100];
int *secondLevel[100][5000];

int ***constructTable(int A[], int B[]) {
  int idx = 0;
  for (int i = 0; i < 100; ++i) {
    if (A[i] == 0)
      break;
    firstLevel[i] = &secondLevel[i][0];
    for (int j = 0; j < A[i]; ++j) {
      secondLevel[i][j] = &B[idx];
      while (B[++idx] != 0);
      ++idx;
    }
  }
  return &firstLevel[0];
}
