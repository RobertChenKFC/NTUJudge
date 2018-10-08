#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
 
typedef struct {
  int x;
  int y;
  int bikes;
  int cap;
  int idx;
} Lot;
 
int Cmp1(const void *pa, const void *pb) {
  Lot *a = (Lot*)pa, *b = (Lot*)pb;
  if (a->x == b->x) return a->y - b->y;
  return a->x - b->x;
}

int Cmp2(const void *pa, const void *pb) {
  Lot *a = (Lot*)pa, *b = (Lot*)pb;
  return a->idx - b->idx;
}
 
int Abs(int a) {
  return a >= 0 ? a : (-a);
}
 
int main() {
  int n;
  scanf("%d", &n);
  Lot lots[10];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &lots[i].x, &lots[i].y, &lots[i].cap); 
    lots[i].idx = i;
    lots[i].bikes = 0;
  }
 
  qsort(lots, n, sizeof(Lot), Cmp1);

  int m;
  scanf("%d", &m);
  int x, y;
  while (m--) {
    scanf("%d%d", &x, &y);
    int min = INT_MAX, moveTo;
    for (int i = 0; i < n; ++i) {
      int dist = Abs(x - lots[i].x) + Abs(y - lots[i].y);
      if (dist < min && lots[i].cap > lots[i].bikes) {
        min = dist;
        moveTo = i;
      }
    }
    ++lots[moveTo].bikes;
  }

  qsort(lots, n, sizeof(Lot), Cmp2);
 
  for (int i = 0; i < n; ++i)
    printf("%d\n", lots[i].bikes);
}
