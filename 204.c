#include <stdio.h>

int main() {
  int w, d;
  scanf("%d%d", &w, &d);

  int mirrors[100][100];
  for (int i = d - 1; i >= 0; --i) {
    for (int j = 0; j < w; ++j)
      scanf("%d", &mirrors[j][i]);
  }

  int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
  int turn[] = {3, 2, 1, 0};
  for (int i = 0; i < (w + d) * 2; ++i) {
    int x, y, dir;
    if (i < w) {
      x = i;
      y = 0;
      dir = 0;
    } else if (i < w + d) {
      x = w - 1;
      y = i - w;
      dir = 1;
    } else if (i < 2 * w + d) {
      x = 2 * w + d - i - 1;
      y = d - 1;
      dir = 2;
    } else {
      x = 0;
      y = 2 * (w + d) - i - 1;
      dir = 3;
    } 

    while (x >= 0 && x < w && y >= 0 && y < d) {
      if (mirrors[x][y])
        dir = turn[dir];
      x += dx[dir];
      y += dy[dir];
    }

    if (x == -1)
      printf("%d\n", 2 * (w + d) - y - 1); 
    else if (x == w)
      printf("%d\n", w + y);
    else if (y == -1) 
      printf("%d\n", x);
    else
      printf("%d\n", 2 * w + d - x - 1);
  }
}

