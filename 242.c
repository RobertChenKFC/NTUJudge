#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int64_t sq(int64_t x) {
  return x * x;
}

typedef struct {
  int64_t x;
  int64_t y;
} Point;

int Cmp(const void *pa, const void *pb) {
  Point *a = (Point*)pa, *b = (Point*)pb;
  if (a->x == b->x) {
    if (a->y > b->y) return 1;
    if (a->y < b->y) return -1;
    return 0;
  }
  if (a->x > b->x) return 1;
  if (a->x < b->x) return -1;
}

int main() {
  Point points[1200]; 

  int n;
  scanf("%d", &n);
  while (n--) {
    int numPoints = 0;
    for (int i = 0; i < 3; ++i) {
      int64_t cx, cy, r;
      scanf("%ld%ld%ld", &cx, &cy, &r); 
      int64_t xmin = cx - r, xmax = cx + r;
      int64_t ymin = cy - r, ymax = cy + r;
      int64_t rsq = sq(r);
      for (int64_t x = xmin; x <= xmax; ++x) {
        for (int64_t y = ymin; y <= ymax; ++y) {
          if (sq(x - cx) + sq(y - cy) <= rsq) {
            points[numPoints].x = x;
            points[numPoints++].y = y;
          }
        }
      }
    }

    qsort(points, numPoints, sizeof(Point), Cmp);

    Point prev = points[0];
    int cnt = 1;
    int total = 0;
    for (int i = 1; i < numPoints; ++i) {
      if (points[i].x != prev.x || points[i].y != prev.y) {
        if (cnt & 1) ++total;
        prev = points[i];
        cnt = 1;
      } else {
        ++cnt; 
      }
    }
    if (cnt & 1) ++total;

    printf("%d\n", total);
  }
}

