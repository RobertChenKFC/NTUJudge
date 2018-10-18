#include <stdio.h>

int board[100][100];
typedef struct {
  int i;
  int j;
  int stopped;
} Knight;
Knight knights[10000];
typedef struct {
  int di;
  int dj;
} Move;
Move moves[] = {
  {-2, 1},
  {-1, 2},
  {1, 2},
  {2, 1},
  {2, -1},
  {1, -2},
  {-1, -2},
  {-2, -1}
};

int main() {
  int n, m;
  int stepCount = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &knights[i].i, &knights[i].j);
    knights[i].stopped = 0;
    board[knights[i].i][knights[i].j] = 10000 * (i + 1) + stepCount;
  }
   
  ++stepCount;
  while (1) {
    for (int i = 0; i < m; ++i) {
#ifdef DEBUG
      printf("Knight %d\n", i);
#endif
      if (!knights[i].stopped) {
        knights[i].stopped = 1;
        int minMoves = 9;
        int finali = -1, finalj;
        for (int j = 0; j < 8; ++j) {
          int newi = knights[i].i + moves[j].di;
          int newj = knights[i].j + moves[j].dj;
          if (newi >= 0 && newi < n && newj >= 0 && newj < n && !board[newi][newj]) {
            int numMoves = 0;
            for (int k = 0; k < 8; ++k) {
              int possiblei = newi + moves[k].di;
              int possiblej = newj + moves[k].dj;
              if (possiblei >= 0 && possiblei < n && possiblej >= 0 && possiblej < n && !board[possiblei][possiblej])
                ++numMoves;
            }

#ifdef DEBUG
            printf("Move %d: %d possible moves\n", j, numMoves);
#endif

            if (numMoves < minMoves) {
              minMoves = numMoves;
              finali = newi;
              finalj = newj;
            }
          }
        } 
        if (finali != -1) {
          knights[i].i = finali;
          knights[i].j = finalj;
          knights[i].stopped = 0;
          board[finali][finalj] = 10000 * (i + 1) + stepCount;
        }
      }
    }

    int allStopped = 1;
    for (int i = 0; i < m; ++i) {
      if (!knights[i].stopped) {
        allStopped = 0;
        break;
      } 
    }
    if (allStopped) break;

#ifdef DEBUG
    printf("Step %d\n", stepCount);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != 0) printf(" ");
        printf("%05d", board[i][j]);
      } 
      printf("\n");
    }
    printf("\n");
#endif

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

