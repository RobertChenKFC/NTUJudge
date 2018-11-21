#include <stdio.h>

int COUNT[65536];

int BitCount(unsigned long long x) {
  return COUNT[x & 65535ULL] + COUNT[(x >> 16) & 65535ULL] + COUNT[(x >> 32) & 65535ULL] + COUNT[(x >> 48) & 65535ULL];
}

int main() {
  // initialize COUNT array
  for (int i = 0; i < 65536; ++i) {
    int count = 0;
    int x = i;
    while (x) {
      if (x & 1) ++count;
      x >>= 1;
    }
    COUNT[i] = count;
  }
  int n, m;
  unsigned long long features[1030][9];
  while (scanf("%d%d", &n, &m) != EOF) {
    int longs = m / 64 + 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < longs; ++j)
        features[i][j] = 0;
      char s[520];
      scanf("%s", s);
      for (int j = 0; j < m; ++j)
        features[i][j / 64] |= ((unsigned long long)(s[j] - '0')) << (j % 64);
    } 
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int in = 0, un = 0;
        for (int k = 0; k < longs; ++k) {
          in += BitCount(features[i][k] & features[j][k]);
          un += BitCount(features[i][k] | features[j][k]);
        }
        if (un == 0) continue;
        double sim = (double)in / un;

#ifdef DEBUG
        printf("intersection: %d, union: %d, similarity: %lf\n", in, un, sim);
#endif

        if (sim >= 0.8) ++count;
      } 
    }
    printf("%.2lf\n", (double)count / (n * (n - 1) / 2) * 100);
  }  
}

