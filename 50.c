#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x1, y1;
  int x2, y2;
} Rect;

int Cmp(const void *a, const void *b) {
  return (*((int*)a)) - (*((int*)b));
}

Rect ZERO = {0, 0, 0, 0};

Rect Intersection(Rect a, Rect b) {
  if ((a.x2 < b.x1 || a.y2 < b.y1) ||
      (b.x2 < a.x1 || b.y2 < a.y1)) return ZERO;
  int x[4], y[4];
  x[0] = a.x1;
  x[1] = a.x2;
  x[2] = b.x1;
  x[3] = b.x2;
  y[0] = a.y1;
  y[1] = a.y2;
  y[2] = b.y1;
  y[3] = b.y2;
  qsort(x, 4, sizeof(int), Cmp); 
  qsort(y, 4, sizeof(int), Cmp); 
  Rect ret;
  ret.x1 = x[1];
  ret.x2 = x[2];
  ret.y1 = y[1];
  ret.y2 = y[2];
  return ret;
}

int Area(Rect rect) {
  return (rect.x2 - rect.x1) * (rect.y2 - rect.y1); 
}

int main() {
  Rect rect[3];
  for (int i = 0; i < 3; ++i) 
    scanf("%d%d%d%d", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2);

  int area = Area(rect[0]) + Area(rect[1]) + Area(rect[2]);
  area -= Area(Intersection(rect[0], rect[1])) + Area(Intersection(rect[1], rect[2])) + Area(Intersection(rect[2], rect[0]));
  area += Area(Intersection(Intersection(rect[0], rect[1]), rect[2]));
  printf("%d\n", area);
}
