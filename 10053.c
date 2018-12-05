#include <stdio.h>

int map[5][5];
int n;
int firstWin, secondWin, draw;
void Count(int first, int second, int isFirst, int row, int col) {
  int nothing = 1;
  if (isFirst) {
    for (int i = 0; i < n; ++i) {
      if (map[row][i] != -1) {
        nothing = 0;
        int original = map[row][i];
        map[row][i] = -1;
        Count(first + original, second, 0, row, i);
        map[row][i] = original;
      } 
    } 
  } else {
    for (int i = 0; i < n; ++i) {
      if (map[i][col] != -1) {
        nothing = 0;
        int original = map[i][col];
        map[i][col] = -1;
        Count(first, second + original, 1, i, col);
        map[i][col] = original;
      } 
    } 
  }
  if (nothing) {
    if (first > second) ++firstWin;
    else if (first < second) ++secondWin;
    else ++draw;
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    firstWin = secondWin = draw = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        scanf("%d", &map[i][j]);
    } 
    Count(0, 0, 1, 0, 0);
    printf("%d %d %d\n", firstWin, secondWin, draw);
  }
}

