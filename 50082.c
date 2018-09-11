#include <stdio.h>

int main() {
  int ra = 0, rb = 0;
  int t, ta, tb;
  while (scanf("%d%d%d", &t, &ta, &tb) != EOF) {
    if (t > ra) ra = t + ta;
    else ra += ta;
    if (ra > rb) rb = ra + tb;
    else rb += tb;
    printf("%d\n", rb);
  }
}
