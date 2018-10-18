#include "nextMove.h"

#include <stdio.h>

typedef struct {
  int r;
  int c;
} Knight;
Knight knights[10000];
int board[100][100] = {0};

int main() {
  static int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  static int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

  int n, m;
  int stepCount = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &knights[i].r, &knights[i].c);
    board[knights[i].r][knights[i].c] = 10000 * (i + 1) + stepCount;
  }
  ++stepCount;

  while (1) {
    int stopped = 1;
    for (int i = 0; i < m; ++i) {
      int next = nextMove(knights[i].r, knights[i].c, n, board);
      if (next != -1) {
        knights[i].r += dr[next];
        knights[i].c += dc[next];
        board[knights[i].r][knights[i].c] = 10000 * (i + 1) + stepCount;
        stopped = 0;
      }
    }

#ifdef DEBUG
    printf("%d\n", stepCount);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != 0) printf(" ");
        printf("%05d", board[i][j]);
      }
      printf("\n");
    }
    printf("\n");
#endif

    if (stopped) break;
    ++stepCount;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j != 0) printf(" ");
      printf("%d", board[i][j]);
    }
    printf("\n");
  }
}

