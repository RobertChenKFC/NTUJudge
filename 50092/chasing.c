#include "chasing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_ABC(x)   ((x) >= 'A' && (x) <= 'C')
#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
  memset(A, 0, sizeof(int) * a);
  memset(B, 0, sizeof(int) * b);
  char str[64];
  while (fgets(str, 64, stdin) != NULL) {
    const char *token = strtok(str, " ");
    int isABC = 1;
    char from = 0, to = 0;
    int fromi = -1, toi = -1;
    int valid = 1;
    while (token != NULL) {
      if (toi != -1) {
        valid = 0;
        break;
      }
      if (isABC) {
        if (strlen(token) != 1 || !IS_ABC(token[0])) {
          valid = 0;
          break;
        } else if (from) {
          to = token[0];
        } else {
          from = token[0];
        }
      } else {
        for (int i = 0; token[i] != '\0' && token[i] != '\n'; ++i) {
          if (!IS_DIGIT(token[i])) {
            valid = 0;
            goto INVALID;
          } 
        }
        if (fromi != -1)  {
          toi = atoi(token);
        } else {
          fromi = atoi(token); 
        }
      }
      isABC = !isABC;
      token = strtok(NULL, " ");
    }

    if (valid) {
      if (from == 'A' && to == 'B') {
        if (fromi >= 0 && fromi < a && toi >= 0 && toi < b)
          A[fromi] = &B[toi];
        else
          valid = 0;
      } else if (from == 'B' && to == 'C') {
        if (fromi >= 0 && fromi < b && toi >= 0 && toi < c)
          B[fromi] = &C[toi];
        else
          valid = 0;
      } else {
        valid = 0; 
      }
    }
    INVALID:
    printf("%d\n", valid);
  }
}
