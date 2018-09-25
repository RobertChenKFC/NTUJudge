#include <stdio.h>

int PrintB(unsigned char x) {
  for (int i = 0; i < 8; ++i) {
    printf("%d", (x & 128) ? 1 : 0);
    x <<= 1;
  }
}

int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  unsigned char validCodes[24];
  int idx = 0;
  while (m--) {
    unsigned long long x;
    scanf("%llu", &x);
    for (int i = 0; i < 8 && idx < n; ++i, ++idx) {
      validCodes[idx] = x >> 56; 
      x <<= 8;
    }
  }
  unsigned char text;
  while (p--) {
    scanf("%hhu", &text);
    int minDist = 9;
    unsigned char correct;
    for (int i = 0; i < n; ++i) {
      int dist = 0;
      for (unsigned char mask = 1; mask != 0; mask <<= 1)
        if ((text & mask) != (validCodes[i] & mask)) ++dist; 
      if (dist < minDist) {
        correct = validCodes[i];
        minDist = dist;
      }
    }
    if (minDist <= 1) printf("%hhu\n", correct);
  }
}
