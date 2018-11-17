#include <stdio.h>

int empty[1005][1005] = {0};
int xs[1000005];
int ys[1000005];

int main() {
  int rows, cols;
  scanf("%d%d", &rows, &cols);
  int n;
  scanf("%d", &n);
  while (n--) {
    int lx, ly, rx, ry;
    scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
    if (ly > ry) {
      int t = ly;
      ly = ry;
      ry = t;
    }
    int rich = 0;
    for (int j = lx; j <= rx; ++j) {
      for (int i = ly; i <= ry; ++i) {
        if (!empty[i][j]) {
          xs[rich] = j;
          ys[rich++] = i; 
          empty[i][j] = 1;
        }
      }
    }
    printf("%d", rich);
    for (int i = 0; i < rich; ++i)
      printf(" (%d, %d)", xs[i], ys[i]);
    printf("\n");
  }
}

