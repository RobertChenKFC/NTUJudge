#include <stdio.h>

int grid[3][3] = {0};

int CheckWin() {
  int full = 1;
  for (int i = 0; i < 3; ++i) {
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < 3; ++j) {
      if (!grid[i][j]) full = 0;
      sum1 += grid[i][j];
      sum2 += grid[j][i];
    }
    if (sum1 == 3 || sum2 == 3) {
      printf("Black wins.\n");
      return 1;
    } else if (sum1 == -3 || sum2 == -3) {
      printf("White wins.\n"); 
      return 1;
    }
  }
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 3; ++i) {
    sum1 += grid[i][i];
    sum2 += grid[i][2 - i];
  }
  if (sum1 == 3 || sum2 == 3) {
    printf("Black wins.\n");
    return 1;
  } else if (sum1 == -3 || sum2 == -3) {
    printf("White wins.\n"); 
    return 1;
  } else if (full) {
    printf("There is a draw.\n");
    return 1;
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int player = 1;
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);

    if (x >= 0 && x < 3 && y >= 0 && y < 3 && !grid[x][y]) {
      grid[x][y] = player;
      player = -player;
      if (CheckWin()) return 0;
    }
  }
  if (CheckWin() == 0) printf("There is a draw.\n");
}

