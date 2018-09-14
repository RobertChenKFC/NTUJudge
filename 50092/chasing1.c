#include "chasing.h"

#include <stdio.h>
#include <string.h>

#define IS_ABC(x)   ((x) >= 'A' && (x) <= 'C')
#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
  memset(A, 0, sizeof(int) * a);
  memset(B, 0, sizeof(int) * b);
  char str[64];
  while (fgets(str, 64, stdin) != NULL) {
    int isABC = 1;
    int valid = 1;
    char from = 0, to = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i) {
      if (str[i] == ' ') {
        isABC = !isABC;
        continue;
      }
      if (isABC) {
        if (!IS_ABC(str[i])) {
          valid = 0;
          break;
        } else if (i != 0 && IS_ABC(str[i - 1])) {
          valid = 0;
          break;
        } else {
          if (from) to = str[i];
          else from = str[i];
        }
      } else {
        if (!IS_DIGIT(str[i])) {
          valid = 0;
          break;
        } 
      }
    }
    if (!((from == 'A' && to == 'B') || (from == 'B' && to == 'C')))
      valid = 0;
    if (valid) {
      if (from == 'A') {
        int ai = -1, bi = -1;
        int i;
        for (i = 0; str[i] != 'B'; ++i) {
          if (IS_DIGIT(str[i])) {
            if (ai == -1)
              ai = 0;
            ai = ai * 10 + (str[i] - '0');
          }
        }
        for (; str[i] != '\0' && str[i] != '\n'; ++i) {
          if (IS_DIGIT(str[i])) {
            if (bi == -1)
              bi = 0;
            bi = bi * 10 + (str[i] - '0');
          }
        }
        if (ai != -1 && ai < a && bi != -1 && bi < b)
          A[ai] = &B[bi];    
        else
          valid = 0;
      } else {
        int bi = -1, ci = -1;
        int i;
        for (i = 0; str[i] != 'C'; ++i) {
          if (IS_DIGIT(str[i])) {
            if (bi == -1)
              bi = 0;
            bi = bi * 10 + (str[i] - '0');
          }
        }
        for (; str[i] != '\0' && str[i] != '\n'; ++i) {
          if (IS_DIGIT(str[i])) {
            if (ci == -1)
              ci = 0;
            ci = ci * 10 + (str[i] - '0');
          }
        }
        if (bi != -1 && bi < b && ci != -1 && ci < c)
          B[bi] = &C[ci];    
        else
          valid = 0;
      }
    }
    printf("%d\n", valid);
  }
}
