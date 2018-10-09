#include <stdio.h>
#include <stdint.h>

int64_t Sqrt(int64_t x) {
  int64_t left = 0, right = x;
  int64_t mid;
  while (left < right) {
    mid = (left + right) / 2;
    int64_t prod = mid * mid;
    int64_t newLeft = left, newRight = right;
    if (prod > x) newRight = mid;
    else if (prod < x) newLeft = mid;
    else break;
    if (newLeft == left && newRight == right) break;
    left = newLeft;
    right = newRight;
  }
  if (left * left == x) return left;
  if (right * right == x) return right;
  return mid;
}
 
int64_t main() {
  int64_t factors[100001];
  int64_t a, b, c;
  scanf("%ld%ld%ld", &a, &b, &c);

  if (c == 0) {
    int64_t d = 0;
    int64_t root = Sqrt(a * a - 4 * b);
    int64_t e = -((-a+root) / 2);
    int64_t f = -((-a-root) / 2);
    if (d > e) {
      int64_t t = d;
      d = e;
      e = t;
    }
    if (e > f) {
      int64_t t = e;
      e = f;
      f = t;
    }
    if (d > e) {
      int64_t t = d;
      d = e;
      e = t;
    }
    printf("%ld %ld %ld\n", d, e, f);
    return 0;
  }

  int64_t numFactors = 0;
  int64_t posc = c >= 0 ? c : (-c);
  for (int64_t i = 1; i <= posc; ++i) {
    if (c % i == 0)
      factors[numFactors++] = i; 
  }

  for (int64_t i = 0; i < numFactors; ++i) {
    for (int64_t j = 0; j < numFactors; ++j) {
      for (int64_t k = 0; k <= 1; ++k) {
        int64_t d = k ? factors[i] : (-factors[i]);
        for (int64_t l = 0; l <= 1; ++l) {
          int64_t e = l ? factors[j] : (-factors[j]);
          int64_t f = a - d - e;
          if (d * e + e * f + f * d == b) {
            if (d > e) {
              int64_t t = d;
              d = e;
              e = t;
            }
            if (e > f) {
              int64_t t = e;
              e = f;
              f = t;
            }
            if (d > e) {
              int64_t t = d;
              d = e;
              e = t;
            }
            printf("%ld %ld %ld\n", d, e, f);
            return 0;
          }
        }
      }
    } 
  }
}
