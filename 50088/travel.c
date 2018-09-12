#include "travel.h"

#include <stdio.h>
#include <limits.h>

int visited[1024][1024] = {0};
int dirs[] = {5, 3, 6, 1, 0, 7, 2, 4};
int rowdirs[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
int coldirs[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]) {
  int max = INT_MIN;
  int min = INT_MAX;
  int idx = 0;
  int astop = 0, bstop = 0;
  while (!astop || !bstop) {
    if (visited[A_r][A_c]) {
      directionA[idx] = -1;
      astop = 1;
    } else {
      visited[A_r][A_c] = 1;
    }
    if (visited[B_r][B_c]) {
      directionB[idx] = -1;
      bstop = 1;
    } else {
      visited[B_r][B_c] = 1;
    }

    int di, dj;
    int curdir = 0;
    int adir = 8, bdir = 8;
    for (di = -1; di <= 1; ++di) {
      for (dj = -1; dj <= 1; ++dj) {
        if (di == 0 && dj == 0)
          continue;
        int ai = A_r + di;
        int aj = A_c + dj;
        if (ai >= 0 && ai < N && aj >= 0 && aj < M && map[ai][aj] > max)
          max = map[ai][aj], adir = dirs[curdir];
        int bi = B_r + di;
        int bj = B_c + dj;
        if (bi >= 0 && bi < N && bj >= 0 && bj < M && map[bi][bj] < min)
          min = map[bi][bj], bdir = dirs[curdir];
        ++curdir;
      } 
    }
    int newA_r = A_r + rowdirs[adir], newA_c = A_c + coldirs[adir];
    int newB_r = B_r + rowdirs[bdir], newB_c = B_c + coldirs[bdir];
    if (A_r == B_r && A_c == B_c) {
      directionA[idx] = directionB[idx] = -1; 
      return;
    }
    if (map[newA_r][newA_c] <= map[A_r][A_c]) {
      directionA[idx] = -1;
      astop = 1;
    }
    if (map[newB_r][newB_c] >= map[B_r][B_c]) {
      directionB[idx] = -1;
      bstop = 1;
    }
    if (!astop) {
      A_r = newA_r, A_c = newA_c;
      directionA[idx] = adir;
    }
    if (!bstop) {
      B_r = newB_r, B_c = newB_c;
      directionB[idx] = bdir;
    }
    ++idx;
  } 
}
