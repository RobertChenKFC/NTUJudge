#include "intersection.h"

void intersection(int map[100][100], int result[4]) {
  result[0] = result[1] = result[2] = result[3] = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j)  {
      if (!map[i][j]) continue;
      int left = i != 0 && map[i - 1][j];
      int right = i != 99 && map[i + 1][j];
      int up = j != 0 && map[i][j - 1];
      int down = j != 99 && map[i][j + 1];
      switch (left + right + up + down) {
      case 4:
        ++result[0];
        break;
      case 3:
        ++result[1];
        break;
      case 2:
        if (!((left && right) || (up && down))) ++result[2];
        break;
      case 1:
        ++result[3];
        break;
      }
    }
  }
}

