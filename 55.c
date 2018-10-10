#include <stdio.h>

int main() {
  int m, n;
  int x1, y1, e1, n1, f1;
  int x2, y2, e2, n2, f2;
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);

  int t = 0;
  int t1 = e1 + n1;
  int t2 = e2 + n2;
  while (f1 > 0 || f2 > 0) {
    if (x1 == x2 && y1 == y2) {
      printf("robots explode at time %d\n", t); 
      return 0;
    }
    if (f1 > 0) {
      if ((t % t1) < n1) y1 = (y1 + 1) % n;
      else x1 = (x1 + 1) % m;
      --f1;
    } 
    if (f2 > 0) {
      if ((t % t2) < e2) x2 = (x2 + 1) % m;
      else y2 = (y2 + 1) % n;
      --f2;
    }
    ++t;
  }
  if (x1 == x2 && y1 == y2)
    printf("robots explode at time %d\n", t); 
  else
    printf("robots will not explode\n");
}

