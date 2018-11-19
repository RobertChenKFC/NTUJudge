#include <stdio.h>
#include <math.h>

#define SGN(X) ((X) == 0 ? 0 : ((X) > 0 ? 1 : (-1)))

int main() {
  long double a, b, c;
  while (scanf("%Lf", &a) != EOF) {
    scanf("%Lf%Lf", &b, &c); 
    long double x1 = (-b - SGN(b) * sqrtl(b * b - 4 * a * c)) / (2 * a);
    long double x2 = c / (a * x1);
    if (x1 > x2) {
      long double t = x1;
      x1 = x2;
      x2 = t;
    }
    printf("%.20Lf %.20Lf\n", x1, x2);
  }
}

