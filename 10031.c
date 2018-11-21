#include <stdio.h>

unsigned long long ABModM(unsigned long long a, unsigned long long b, unsigned long long m) {
  unsigned long long d = 0, mp2 = m >> 1;
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  for (int i = 0; i < 64; ++i) {
    d = (d > mp2) ? (d << 1) - m : d << 1;
    if (a & 0x8000000000000000ULL)
       d += b;
    if (d >= m) d -= m;
    a <<= 1;
  }
  return d;
}

int main() {
  unsigned long long a, b, m;
  while (scanf("%llu%llu%llu", &a, &b, &m) != EOF)
    printf("%llu\n", ABModM(a, b, m)); 
}

