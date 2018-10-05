#include <stdio.h>

#define SQ(x) ((x) * (x))

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a = SQ(x1 - x2) + SQ(y1 - y2);
    double b = SQ(x2 - x3) + SQ(y2 - y3);
    double c = SQ(x3 - x1) + SQ(y3 - y1);
    if (a > b) {
      double t = a;
      a = b;
      b = t;
    }
    if (b > c) {
      double t = b;
      b = c;
      c = t;
    }
    if (a > b) {
      double t = a;
      a = b;
      b = t;
    }
    if (a == b || b == c || c == a)
      printf("isosceles\n");
    else if (a + b > c)
      printf("acute\n");
    else if (a + b == c)
      printf("right\n");
    else
      printf("obtuse\n");
  }
}

