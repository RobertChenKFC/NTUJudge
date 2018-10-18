#include "nextMove.h"
#include "validMoveNum.h"

int nextMove(int r, int c, int n, int visited[100][100]) {
  static int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  static int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

  if (!(r >= 0 && r < n && c >= 0 && c < n)) return -1;

  int move = -1;
  int minP = 9;
  for (int i = 0; i < 8; ++i) {
    int p = validMoveNum(r + dr[i], c + dc[i], n, visited); 
    if (p != -1 && !visited[r + dr[i]][c + dc[i]] && p < minP) {
      minP = p;
      move = i;
    }
  }
  return move;
}

