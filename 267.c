#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y;
} Coord;

Coord origin = {0, 0};

#define SQ(X) ((X) * (X))
int Dist(Coord *a, Coord *b) {
  return SQ(a->x - b->x) + SQ(a->y - b->y);
}

int Cmp(const void *pa, const void *pb) {
  Coord *a = (Coord*)pa, *b = (Coord*)pb;
  int distA = Dist(a, &origin), distB = Dist(b, &origin);
  if (distA == distB) {
    if (a->x == b->x) return a->y - b->y;
    return a->x - b->x;
  }
  return distA - distB;
}

int main() {
  Coord coords[100005];
  int idx = 0;
  int x, y;
  while (scanf("%d%d", &x, &y) != EOF) {
    coords[idx].x = x;
    coords[idx++].y = y;
  }
  qsort(coords, idx, sizeof(Coord), Cmp);
  int dist = 0;
  for (int i = 0; i < idx; ++i) {
    if (i == 0) dist += Dist(&coords[i], &origin);
    else dist += Dist(&coords[i - 1], &coords[i]);
  }
  printf("%d\n", dist);
}

