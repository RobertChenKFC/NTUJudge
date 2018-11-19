#include "fraction.h"

int Abs(int x) {
  return x > 0 ? x : (-x);
}

long long gcd(long long a, long long b) {
  int r = a % b;
  if (r == 0) return b;
  return gcd(b, r);
}

long long Gcd(long long a, long long b) {
  return (a > b) ? gcd(a, b) : gcd(b, a);
}
 
Frac normal(long long a, long long b) {
  if (a == 0) {
    Frac f = {0, 1};
    return f;
  }
  long long x = Gcd(Abs(a), Abs(b));
  Frac f = {a / x, b / x};
  if (f.b < 0) {
    f.a = -f.a;
    f.b = -f.b;
  }
  return f;
}

Frac add(Frac x, Frac y) {
  return normal(x.a * y.b + x.b * y.a, x.b * y.b);
}

Frac subtract(Frac x, Frac y) {
  return normal(x.a * y.b - x.b * y.a, x.b * y.b);
}

Frac multipy(Frac x, Frac y) {
  return normal(x.a * y.a, x.b * y.b);
}

Frac divide(Frac x, Frac y) {
  return normal(x.a * y.b, x.b * y.a);
}

