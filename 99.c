#include <stdio.h>

typedef struct {
  int i;
  int j;
} Pos;

typedef struct {
  char name[64];
  Pos pos[65537];
  int chosen[256][256];
} Player;

int main() {
  Player players[10] = {0};
  int n, m;
  int x;
  scanf("%d%d", &n, &m);
  for (int p = 0; p < n; ++p) {
    scanf("%s", players[p].name); 
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &x); 
        players[p].pos[x].i = i;
        players[p].pos[x].j = j;
      }
    }
  }
  int win = 0;
  while (!win && scanf("%d", &x) != EOF) {
    for (int p = 0; p < n; ++p) {
      players[p].chosen[players[p].pos[x].i][players[p].pos[x].j] = 1; 
      for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
          if (players[p].chosen[i][j]) ++sum;
          else break;
        }
        if (sum == m) {
          if (!win) printf("%d", x);
          win = 1;
          printf(" %s", players[p].name);
          goto NEXT_PLAYER;
        }
      }
      for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
          if (players[p].chosen[j][i]) ++sum;
          else break;
        }
        if (sum == m) {
          if (!win) printf("%d", x);
          win = 1;
          printf(" %s", players[p].name);
          goto NEXT_PLAYER;
        }
      }
      int sum1 = 0, sum2 = 0;
      for (int i = 0; i < m; ++i) {
        sum1 += players[p].chosen[i][i];
        sum2 += players[p].chosen[i][m - 1 - i];
      }
      if (sum1 == m || sum2 == m) {
        if (!win) printf("%d", x);
        win = 1;
        printf(" %s", players[p].name);
        goto NEXT_PLAYER;
      }
NEXT_PLAYER:
      continue;
    } 
  }
  printf("\n");
}

