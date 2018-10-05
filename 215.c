#include <stdio.h>

double Int(double x)  {
  return (double)((int)x);
}

int main() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  double s = x, f = y, t = z;

  double c = s - t;
  double b = ((f - c * 8) / 2) - t;
  double a = t - b;
  if (a >= 0 && b >= 0 && c >= 0 &&
      a == Int(a) && b == Int(b) && c == Int(c))
    printf("%d\n%d\n%d\n", (int)a, (int)b, (int)c);
  else
    printf("0\n");
}

