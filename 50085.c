#include <stdio.h>
#include <string.h>

int main() {
  int n, m, l, w;
  scanf("%d%d%d%d", &m, &n, &l, &w);

  int map[n][m];
  memset(map, 0, sizeof(map));
  int nObstacles = 0;
  scanf("%d", &nObstacles);
  int x, y;
  while (nObstacles--) {
    scanf("%d%d", &x, &y);
    map[x][y] = 2;
  }

  int instruction;
  x = y = 0;
  while (scanf("%d", &instruction) != EOF) {
    switch (instruction) {
    case 0:
      for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
          if (i >= x && i < x + w && j >= y && j < y + l)
            printf("1");
          else 
            printf("%d", map[i][j]);
        }
        printf("\n");
      }
      break;
    case 1: {
      int i = x + w;
      if (i >= n)
        break;
      int count = 0;
      for (int j = y; j < y + l; ++j) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break;
          }
        }
      }
      for (int j = y; count <= 1 && j < y + l; ++j) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      if (count <= 1)
        ++x;
      break;
    }
    case 2: {
      int j = y + l;
      if (j >= m)
        break;
      int count = 0;
      for (int i = x; i < x + w; ++i) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break;
          }
        }
      }
      for (int i = x; count <= 1 && i < x + w; ++i) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      if (count <= 1)
        ++y;
      break;
    }
    case 3: {
      int i = x - 1;
      if (i < 0)
        break;
      int count = 0;
      for (int j = y; j < y + l; ++j) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break;
          }
        }
      }
      for (int j = y; count <= 1 && j < y + l; ++j) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      if (count <= 1)
        --x;
      break;
    }
    case 4: {
      int j = y - 1;
      if (j < 0)
        break;
      int count = 0;
      for (int i = x; i < x + w; ++i) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break;
          }
        }
      }
      for (int i = x; count <= 1 && i < x + w; ++i) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      if (count <= 1)
        --y;
      break;
    } 
    case 5: {
      int count = 0;
      int i = x + w;
      if (i >= n)
        break;
      int j;
      for (j = y + 1; j < y + l; ++j) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break; 
          } 
        } 
      }
      j = y + l;
      if (j >= m)
        break;
      for (i = x + 1; count <= 1 && i < x + w; ++i) {
        if (map[i][j] == 2) {
          if (++count == 2) {
            break; 
          } 
        } 
      }
      i = x + w;
      if (map[i][j] == 2)
        ++count;
      for (j = y + 1; count <= 1 && j < y + l; ++j) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      j = y + l;
      for (i = x + 1; count <= 1 && i < x + w; ++i) {
        if (map[i][j] == 2)
          map[i][j] = 0;
      }
      i = x + w;
      if (count <= 1 && map[i][j] == 2)
        map[i][j] = 0; 
      if (count <= 1)
        ++x, ++y;
    }
    }
  }
}
