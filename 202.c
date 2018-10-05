#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  int r = a % b;
  if (r == 0) return b;
  return gcd(b, r);
}

int main() {
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

  if (a < 0) b = -b;
  if (e < 0) f = -f;
  
  int q, p;
  switch (d) {
  case 0: 
    q = (a * c + b) * g + (e * g + f) * c;
    p = c * g;
    break;
  case 1:
    q = (a * c + b) * g - (e * g + f) * c;
    p = c * g;
    break;
  case 2:
    q = (a * c + b) * (e * g + f);
    p = c * g;
    break;
  case 3:
    q = (a * c + b) * g;
    p = (e * g + f) * c;
    break;
  }

  if (p < 0) {
    p = -p;
    q = -q;
  }
  if (q < 0) {
    printf("-");
    fflush(stdin);
    q = -q;
  }
  int div;
  if (p >= q) div = gcd(p, q);
  else div = gcd(q, p);
  p /= div;
  q /= div;
  printf("%d\n%d\n%d\n", q / p, q % p, p);
}

