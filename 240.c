#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  double x;
  double y;
} Point;

double Cross(Point *prev, Point *cur, Point *next) {
  return (prev->x - cur->x) * (next->y - cur->y) - (prev->y - cur->y) * (next->x - cur->x);
}

int perm[4];
Point points[4];
char inPerm[4];
int Permutation(int cur, int idx) {
  if (idx == 3) {
    perm[idx] = cur;
    int clockwise = 0, counterClockwise = 0;
    for (int i = 0; i < 4; ++i) {
      int mid = perm[i];
      int prev = (i == 0) ? perm[3] : perm[i - 1];
      int next = (i == 3) ? perm[0] : perm[i + 1];
      double cross = Cross(&points[prev], &points[mid], &points[next]);
      clockwise += cross > 0;
      counterClockwise += cross < 0;
    }
    return (clockwise == 4 || counterClockwise == 4);
  } 

  inPerm[cur] = 1;
  perm[idx] = cur;
  for (int i = 0; i < 4; ++i) {
    if (!inPerm[i]) {
      if (Permutation(i, idx + 1))
        return 1;
    } 
  }
  inPerm[cur] = 0;
  return 0;
}

int IsRight(Point *prev, Point *cur, Point *next) {
  return (prev->x - cur->x) * (next->x - cur->x) + (prev->y - cur->y) * (next->y - cur->y) == 0;
}

#define SQ(x) ((x) * (x))
int DistSq(Point *a, Point *b) {
  return SQ(a->x - b->x) + SQ(a->y - b->y);
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    for (int i = 0; i < 4; ++i)
      scanf("%lf%lf", &points[i].x, &points[i].y);

    for (int i = 0; i < 4; ++i) {
      memset(inPerm, 0, sizeof(inPerm));
      if (Permutation(i, 0)) break;
    }

    int allRights = 1;
    double prevDist = -1;
    int distAllSame = 1;
    for (int i = 0; i < 4; ++i) {
      int mid = perm[i];
      int prev = (i == 0) ? perm[3] : perm[i - 1];
      int next = (i == 3) ? perm[0] : perm[i + 1];
      allRights = allRights && IsRight(&points[prev], &points[mid], &points[next]);
      double dist = DistSq(&points[mid], &points[next]);
      if (prevDist != -1 && dist != prevDist)
        distAllSame = 0;
      prevDist = dist;
    }

    if (allRights) {
      if (distAllSame) printf("square\n"); 
      else printf("rectangle\n");
    } else {
      if (distAllSame) printf("diamond\n"); 
      else printf("other\n");
    }
  }
}

