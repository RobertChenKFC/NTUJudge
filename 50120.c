#include <stdio.h>

int arr[1000][1000];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%d", &arr[i][j]);
  }

  int maxLen = -1;
  int rowLen = 0, colLen = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j]) ++rowLen;
      else rowLen = 0;
      if (arr[j][i]) ++colLen;
      else colLen = 0;
      if (rowLen > maxLen) maxLen = rowLen;
      if (colLen > maxLen) maxLen = colLen;
    } 
    rowLen = colLen = 0;
  }

  int leftDiag = 0, rightDiag = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i, k = 0; j < n && k < n; ++j, ++k) {
      if (arr[j][k]) ++leftDiag;
      else leftDiag = 0;
#ifdef DEBUG
      printf("%d %d: %d\n", j, k, leftDiag);
#endif
      if (arr[k][j]) ++rightDiag;
      else rightDiag = 0;
      if (leftDiag > maxLen) maxLen = leftDiag;
      if (rightDiag > maxLen) maxLen = rightDiag;
    } 
    leftDiag = rightDiag = 0;
  }

  printf("%d\n", maxLen);
}

