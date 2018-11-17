#include <stdio.h>

int gcd(int a, int b) {
  int r = a % b;
  return r == 0 ? b : gcd(b, r);
}

int Gcd(int a, int b) {
  return a > b ? gcd(a, b): gcd(b, a);
}

int main() {
  int p, q;
  while (scanf("%d", &q) != EOF) {
    scanf("%d", &p); 
    if (q == 0) {
      printf("0 / 1\n");
    } else if (p != 0) {
      int d = Gcd(p, q);
      printf("%d / %d\n", q / d, p / d);
    }
  }
}

