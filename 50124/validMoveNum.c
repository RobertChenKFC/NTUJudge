#include "validMoveNum.h"

int validMoveNum(int r, int c, int n, int visited[100][100]) {
  static int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  static int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

  if (!(r >= 0 && r < n && c >= 0 && c < n)) return -1;
  int validMoves = 0;
  for (int i = 0; i < 8; ++i) {
    int newi = r + dr[i];
    int newj = c + dc[i];
    if (newi >= 0 && newi < n && newj >= 0 && newj < n && !visited[newi][newj])
      ++validMoves;
  }
  return validMoves;
}

