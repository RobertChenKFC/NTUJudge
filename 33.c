#include <stdio.h>

int main() {
  int map[100][100];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)  
      scanf("%d", &map[i][j]);
  }
  int intersections = 0, ts = 0, turns = 0, deadEnds = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)  {
      if (!map[i][j]) continue;
      int left = i != 0 && map[i - 1][j];
      int right = i != n - 1 && map[i + 1][j];
      int up = j != 0 && map[i][j - 1];
      int down = j != n - 1 && map[i][j + 1];
      switch (left + right + up + down) {
      case 4:
        ++intersections;
        break;
      case 3:
        ++ts;
        break;
      case 2:
        if (!((left && right) || (up && down))) ++turns;
        break;
      case 1:
        ++deadEnds;
        break;
      }
    }
  }
  printf("%d\n%d\n%d\n%d\n", intersections, ts, turns, deadEnds);
}

