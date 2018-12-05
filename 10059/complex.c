#include "complex.h"

#include <stdio.h>

void init(complex *c, float a, float b) {
  c->a = a;
  c->b = b;
}

void complex_print(complex *x) {
  if (x->b < 0) printf("%.3f-%.3fi\n", x->a, -x->b);
  else printf("%.3f+%.3fi\n", x->a, x->b);
}

complex complex_add(complex *x, complex *y) {
  complex ret;
  ret.a = x->a + y->a;
  ret.b = x->b + y->b;
  return ret;
}

complex complex_sub(complex *x, complex *y) {
  complex ret;
  ret.a = x->a - y->a;
  ret.b = x->b - y->b;
  return ret;
}

complex complex_mul(complex *x, complex *y) {
  complex ret;
  ret.a = x->a * y->a - x->b * y->b;
  ret.b = x->a * y->b + x->b * y->a;
  return ret;
}

