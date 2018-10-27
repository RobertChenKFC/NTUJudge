#include "findLength.h"

#include <stdio.h>
 
int main() {
  int map[256][256];
 
  int n;
  scanf("%d", &n);
 
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &map[i][j]);
 
  int len, maxLen = 0;
  for (int i = 0; i < n; ++i) {
    // col 
    len = findLength(map, n, i, 0, 0, 1);
    if (len > maxLen) maxLen = len;
    // row
    len = findLength(map, n, 0, i, 1, 0);
    if (len > maxLen) maxLen = len;
    // left half diag (bottom right)
    len = findLength(map, n, i, 0, 1, 1);
    if (len > maxLen) maxLen = len;
    // right half diag (bottom right)
    len = findLength(map, n, 0, i, 1, 1);
    if (len > maxLen) maxLen = len;
    // left half diag (bottom left)
    len = findLength(map, n, i, 0, 1, -1);
    if (len > maxLen) maxLen = len;
    // right half diag (bottom left)
    len = findLength(map, n, 0, i, 1, -1);
    if (len > maxLen) maxLen = len;
  }
  printf("%d\n", maxLen);
}
