#include <stdio.h>

int Gcd(int a, int b) {
  int r = a % b;
  if (r == 0) return b;
  return Gcd(b, r);
}

int Lcm(int a, int b) {
  return a * b / Gcd(a, b);
}

int main() {
  int lcm = 1;
  int x;
  while (scanf("%d", &x) != EOF)
    lcm = (lcm > x) ? Lcm(lcm, x) : Lcm(x, lcm); 
  printf("%d\n", lcm);
}

