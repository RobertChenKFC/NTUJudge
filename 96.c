#include <stdio.h>

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);

  double PI = 3.1415926;
  double area = 0;

  double len1 = c - b;
  if (len1 > 0) {
    double len2 = len1 - a;
    if (len2 > 0) area += len2 * len2 * PI / 4;
    area += len1 * len1 * PI / 4;
  }
  len1 = c - a;
  if (len1 > 0) {
    double len2 = len1 - b;
    if (len2 > 0) area += len2 * len2 * PI / 4;
    area += len1 * len1 * PI / 4;
  }
  area += c * c * PI * 3 / 4;
  printf("%lf\n", area); 
}

