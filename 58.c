#include <stdio.h>
#include <stdlib.h>

int map[405][405];
int lakes[80005];
int n, m;

int Cmp(const void *a, const void *b) {
  return *((int*)b) - *((int*)a);
}

int DFS(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || !map[i][j]) return 0;
  map[i][j] = 0;
  return 1 + DFS(i - 1, j) + DFS(i, j - 1) + DFS(i + 1, j) + DFS(i, j + 1);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      scanf("%d", &map[i][j]);
  }

  int nLakes = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j]) {
        int area = DFS(i, j);
        if (area != 0)
          lakes[nLakes++] = area; 
      }
    } 
  }
  
  qsort(lakes, nLakes, sizeof(int), Cmp);
  for (int i = 0; i < nLakes; ++i)
    printf("%d\n", lakes[i]);
}

