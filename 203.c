#include <stdio.h>

int main() {
  int X, Y;
  int x1, y1, x2, y2;
  int dx1, dy1, dx2, dy2;
  int t;

  scanf("%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);

  while (t--) {
    int newx1 = x1 + dx1, newy1 = y1 + dy1;
    int newx2 = x2 + dx2, newy2 = y2 + dy2;
    if (newx1 <= 0 || newx1 > X) {
      dx1 = -dx1; 
      newx1 = x1 + dx1;
    }
    if (newy1 <= 0 || newy1 > Y) {
      dy1 = -dy1;
      newy1 = y1 + dy1;
    } 
    if (newx2 <= 0 || newx2 > X) {
      dx2 = -dx2; 
      newx2 = x2 + dx2;
    }
    if (newy2 <= 0 || newy2 > Y) {
      dy2 = -dy2;
      newy2 = y2 + dy2;
    } 
    if (newx1 == newx2 && newy1 == newy2) {
      int t = dx1;
      dx1 = dx2;
      dx2 = t;
      t = dy1;
      dy1 = dy2;
      dy2 = t;
    } 

    x1 = newx1;
    y1 = newy1;
    x2 = newx2;
    y2 = newy2;
  } 

  printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);
}

