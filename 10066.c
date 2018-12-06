#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

double frand() {
  return 2 * ((double)rand() / RAND_MAX) - 1;
}

double DistSq(double x1, double y1, double z1, double x2, double y2, double z2) {
  double dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
  return dx * dx + dy * dy + dz * dz;
}

const int SIMULATIONS = 5000000;

int main() {
  int r, n;
  int xs[10], ys[10], zs[10];
  int caseIdx = 1;
  while (scanf("%d%d", &r, &n) != EOF) {
    for (int i = 0; i < n; ++i)
      scanf("%d%d%d", &xs[i], &ys[i], &zs[i]);
    int count[10] = {0};
    int sims = 0;
    for (int k = 0; k < SIMULATIONS; ++k) {
      double min = -1;
      int idx;
      double x = r * frand(), y = r * frand(), z = r * frand(); 
      if (x * x + y * y + z * z > (double)r * r) continue;
      ++sims;
      for (int i = 0; i < n; ++i) {
        double distSq = DistSq(x, y, z, xs[i], ys[i], zs[i]);
        if (distSq < min || min == -1)
          min = distSq, idx = i;
      }
      ++count[idx];

#ifdef DEBUG
      if (k != 0 && k % 500000 == 0) {
        for (int i = 0; i < n; ++i)
          printf("%d\n", (int)round((double)count[i] / k * 100));
        printf("\n");
      }
#endif
    }
    printf("Case #%d:\n", caseIdx++);
    for (int i = 0; i < n; ++i)
      printf("%d\n", (int)round((double)count[i] / sims * 100));
  }
}
