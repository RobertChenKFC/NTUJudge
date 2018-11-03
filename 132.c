#include <stdio.h>
#include <string.h>

int map[25][25] = {0};
int colors[25];
int n, c;

int Fill(int country) {
  if (country == n) return 1;
  for (int color = 0; color < c; ++color) {
    int valid = 1;
    for (int i = 0; i < n; ++i) {
      if (i != country && map[i][country] && colors[i] == color) {
        valid = 0;
        break;
      }
    }
    if (valid) {
      colors[country] = color;
      int success = Fill(country + 1);
      if (success) return 1;
      colors[country] = -1;
    }
  }
  return 0;
}

int main() {
  memset(colors, -1, sizeof(colors));
  int p;
  scanf("%d%d%d", &n, &c, &p);
  while (p--) {
    int i, j;
    scanf("%d%d", &i, &j);
    map[i][j] = map[j][i] = 1;
  }
  if (Fill(0)) {
    for (int i = 0; i < n; ++i)
      printf("%d\n", colors[i] + 1);
  } else {
    printf("no solution.\n"); 
  }
}

