#include <stdio.h>

int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  int w;
  if (r) {
    while (scanf("%d", &w) != EOF) {
      int tn = n - w;
      int tm = m - w;
      
      if (tn < 0) {
        if (tm >= 0) m = tm;  
      } else if (tm < 0) {
        if (tn >= 0) n = tn;
      } else if (tn <= tm) {
        n = tn;
      } else {
        m = tm;
      }
      printf("%d %d\n", n, m);
    } 
  } else {
    while (scanf("%d", &w) != EOF) {
      if (n >= w) {
        n -= w; 
      } else if (m >= w) {
        m -= w; 
      }
      printf("%d %d\n", n, m);
    } 
  }
}
