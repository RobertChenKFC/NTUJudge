#include <stdio.h>
#include <limits.h>
#include <string.h>

char friends[11][11] = {0};
char inPerm[11] = {0};
int perm[11];
int bestPerm[11];
int n;

int abs(int x) {
  return x >= 0 ? x : (-x);
}

int try(int cur, int idx, int curDist, int curMin) {
  perm[cur] = idx;
  inPerm[cur] = 1;
  /*
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (!inPerm[i]) continue;
    for (int j = i + 1; j < n; ++j)
      if (friends[i][j] && inPerm[j]) {
        sum += abs(perm[i] - perm[j]);
        if (sum >= curMin) {
          inPerm[cur] = 0;
          return sum;
        }
      }
  }
  */
  for (int i = 0; i < n; ++i) {
    if (friends[cur][i] && inPerm[i]) {
      curDist += abs(perm[cur] - perm[i]);
      if (curDist >= curMin) {
        inPerm[cur] = 0;
        return curDist;
      }
    }
  }

  if (idx == n - 1) {
    inPerm[cur] = 0;
    return curDist;
  }

  int min = curMin;
  for (int i = 0; i < n; ++i) {
    if (!inPerm[i]) {
      int dist = try(i, idx + 1, curDist, min);
      if (dist < min) min = dist;
    } 
  }
  inPerm[cur] = 0;
  return min;
}

int main() {
  int f;
  scanf("%d%d", &n, &f);
  int x, y;
  while (f--) {
    scanf("%d%d", &x, &y);
    friends[x][y] = friends[y][x] = 1;
  }

  int min = INT_MAX;
  for (int i = 0; i < n; ++i) {
    memset(inPerm, 0, n);
    int dist = try(i, 0, 0, min); 
    if (dist < min) min = dist;
  }
  printf("%d\n", min);
}

