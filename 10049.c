#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double frand() {
  return (double)rand() / RAND_MAX;
}

double DistSq(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

const int SIMULATIONS = 10000000;

int main() {
  int n, a, b;
  int xs[10], ys[10];
  int caseCnt = 1;
  while (scanf("%d%d%d", &n, &a, &b) != EOF) {
    for (int i = 0; i < n; ++i)
      scanf("%d%d", &xs[i], &ys[i]);
    int count[10] = {0};
    for (int k = 0; k < SIMULATIONS; ++k) {
      double x = frand() * a, y = frand() * b;
      double min = -1;
      int idx; 
      for (int i = 0; i < n; ++i) {
        double distSq = DistSq(x, y, xs[i], ys[i]);
        if (distSq < min || min == -1)
          min = distSq, idx = i;
      }
      ++count[idx];
    }
    printf("Case #%d:\n", caseCnt++);
    for (int i = 0; i < n; ++i)
      printf("%d\n", (int)round((double)count[i] / SIMULATIONS * 100));
  }
}

