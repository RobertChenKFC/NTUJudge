#include <stdio.h>

typedef struct {
  int q;
  int p;
} Frac;

int Gcd(int a, int b) {
  int r = a % b;
  if (r == 0) return b;
  return Gcd(b, r);
}

void Reduce(Frac *x) {
  if (x->q == 0) {
    x->p = 1;
    return;
  }
  int gcd = Gcd(x->p, x->q);
  x->p /= gcd;
  x->q /= gcd;
}

Frac Add(Frac a, Frac b) {
  Frac ret;
  ret.q = a.q * b.p + a.p * b.q;
  ret.p = a.p * b.p;
  Reduce(&ret);
  return ret;
}

Frac Mul(Frac a, Frac b) {
  Frac ret;
  ret.q = a.q * b.q;
  ret.p = a.p * b.p;
  Reduce(&ret);
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  Frac prob[n + 1];
  Frac buf[n + 1];
  Frac zero = {0, 1};
  for (int i = 0; i < n + 1; ++i)
    prob[i] = buf[i] = zero;
  prob[0].q = 1;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    for (int j = 0; j < i + 1; ++j)
      buf[j] = zero;
    for (int j = 0; j < i; ++j) {
      scanf("%d%d", &a, &b); 
      Frac left = {a, a + b};
      Frac right = {b, a + b};
      Reduce(&left);
      Reduce(&right);
      buf[j] = Add(buf[j], Mul(left, prob[j]));
      buf[j + 1] = Add(buf[j + 1], Mul(right, prob[j]));
    }
    for (int j = 0; j < i + 1; ++j)
      prob[j] = buf[j]; 
  }
  for (int i = 0; i < n + 1; ++i)
    printf("%d/%d\n", prob[i].q, prob[i].p);
}

