#include <stdio.h>
#include <string.h>

int main() {
  int clear[15][15];
  int r, c;
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      scanf("%d", &clear[i][j]);
  }

  int ways[15][15] = {0};
  int reachable = 1;
  for (int i = r - 1; i >= 0; --i) {
    if (!clear[i][0]) reachable = 0;
    ways[i][0] = reachable;
  }
  reachable = 1;
  for (int i = 0; i < c; ++i) {
    if (!clear[r - 1][i]) reachable = 0;
    ways[r - 1][i] = reachable;
  }

#ifdef DEBUG
  printf("start: \n");
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d ", ways[i][j]); 
    }
    printf("\n");
  }
  printf("\n");
#endif

  for (int i = r - 2; i >= 0; --i) {
    for (int j = 1; j < c; ++j) {
      if (clear[i][j])
        ways[i][j] = ways[i][j - 1] + ways[i + 1][j]; 
    }
  }

#ifdef DEBUG
  printf("final: \n");
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d ", ways[i][j]); 
    }
    printf("\n");
  }
  printf("\n");
#endif

  printf("%d\n", ways[0][c - 1]);
}

