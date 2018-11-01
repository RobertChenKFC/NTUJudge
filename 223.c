#include <stdio.h>

void Tile(int type, int x, int y, int len) {
  if (len == 2) {
    printf("%d %d %d\n", type, x, y);
    return;
  }
  int half = len / 2;
  int block = half / 2;
  switch (type) {
  case 1:
    Tile(1, x, y, half);
    Tile(1, x - block, y - block, half);
    Tile(2, x + block, y - block, half);
    Tile(4, x - block, y + block, half);
    break;
  case 2:
    Tile(2, x, y, half);
    Tile(2, x + block, y - block, half);
    Tile(1, x - block, y - block, half);
    Tile(3, x + block, y + block, half);
    break;
  case 3:
    Tile(3, x, y, half);
    Tile(3, x + block, y + block, half);
    Tile(2, x + block, y - block, half);
    Tile(4, x - block, y + block, half);
    break;
  case 4:
    Tile(4, x, y, half);
    Tile(4, x - block, y + block, half);
    Tile(1, x - block, y - block, half);
    Tile(3, x + block, y + block, half);
    break;
  }
}

int main() {
  int l, m;
  scanf("%d%d", &l, &m);
  int x = 0, y = 0;
  int to = l - m;
  do {
    int half = l / 2;
    x += half;
    y += half;
    Tile(1, x, y, l);
    l = half;
  } while (x != to);
}

