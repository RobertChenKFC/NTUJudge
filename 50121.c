#include <stdio.h>
 
int n, m;
#define IN_RANGE(a, b) (a >= 0 && a < n && b >= 0 && b < m)
 
int main() {
  scanf("%d%d", &n, &m);
 
  int row, col, energy;
  scanf("%d%d%d", &row, &col, &energy);
 
  int stones;
  scanf("%d", &stones);
  int y, x;
  int map[500][500] = {0};
  while (stones--) {
    scanf("%d%d", &y, &x);
    scanf("%d", &map[y][x]);
  } 
 
  int dcol[] = {0, 1, 0, -1, 0};
  int drow[] = {0, 0, 1, 0, -1};
 
  int instruction;
  while (scanf("%d", &instruction) != EOF) {
    if (instruction == 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (j != 0) printf(" ");
          if (i == row && j == col) printf("%d", energy);
          else printf("%d", map[i][j]);
        } 
        printf("\n");
      } 
    } else {
      int newRow = row + drow[instruction];
      int newCol = col + dcol[instruction];
 
      int count = 0;
      int weights = 0;
      int ok = 0;
      for (int i = newRow, j = newCol; IN_RANGE(i, j); i += drow[instruction], j += dcol[instruction]) {
        if (map[i][j]) {
          weights += map[i][j];
          ++count;
        } else {
          ok = 1;
          break;
        }
      }
 
      if (ok && weights <= energy) {
        for (int i = newRow + count * drow[instruction], j = newCol + count * dcol[instruction];
                 i != newRow || j != newCol;
                 i -= drow[instruction], j -= dcol[instruction]) {
          map[i][j] = map[i - drow[instruction]][j - dcol[instruction]];
        }
        map[row][col] = 0;
        row = newRow;
        col = newCol;
        energy -= weights;
      }
    }
  }
}
