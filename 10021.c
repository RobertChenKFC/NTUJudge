#include <stdio.h>
#include <string.h>

void FillSides(int *ways, int *map, int n) {
  int ended = 0;
  for (int i = 0; i < n; ++i) {
    if (!map[i] || ended) {
      ways[i] = 0;
      ended = 1;
    } else {
      ways[i] = 1; 
    }
  }
}

int main() {
  int rows, cols;
  int map[105][105];
  int ways[105][105];
  while (scanf("%d", &rows) != EOF) {
    scanf("%d", &cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j)
        scanf("%d", &map[i][j]);
    }

    int ended = 0;
    for (int i = 0; i < rows; ++i) {
      if (map[i][0] || ended) {
        ways[i][0] = 0; 
        ended = 1;
      } else {
        ways[i][0] = 1;  
      }
    }
    ended = 0;
    for (int i = 0; i < cols; ++i) {
      if (map[0][i] || ended) {
        ways[0][i] = 0; 
        ended = 1;
      } else {
        ways[0][i] = 1;  
      }
    }

#ifdef DEBUG
    printf("Starting position: \n");
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j)
        printf("%d ", ways[i][j]);
      printf("\n");
    }
#endif

    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; ++j)
        ways[i][j] = map[i][j] ? 0 : ((ways[i - 1][j] % 10000) + (ways[i][j - 1] % 10000)) % 10000; 
    }

#ifdef DEBUG
    printf("End position: \n");
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j)
        printf("%d ", ways[i][j]);
      printf("\n");
    }
#endif

    printf("%d\n", ways[rows - 1][cols - 1]);
  }
}

