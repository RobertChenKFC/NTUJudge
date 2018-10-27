#include "findLength.h"
 
int findLength(int array[][256], int N, int r, int c, int dr, int dc) {
  int len = 0, maxLen = 0;
  while (r >= 0 && r < N && c >= 0 && c < N) {
    if (array[r][c]) ++len;
    else len = 0;
    if (len > maxLen) maxLen = len;
    r += dr;
    c += dc;
  }  
  return maxLen;
}
