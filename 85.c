#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int year;
  int month;
  int day;
} Date;

int Cmp(const void *pa, const void *pb) {
  Date *a = (Date*)pa, *b = (Date*)pb;
  if (a->year == b->year) {
    if (a->month == b->month) return a->day - b->day;
    return a->month - b->month;
  }
  return a->year - b->year;
}

Date dates[1000005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d%d", &dates[i].year, &dates[i].month, &dates[i].day);
  qsort(dates, n, sizeof(Date), Cmp);
  for (int i = 0; i < n; ++i)
    printf("%d %d %d\n", dates[i].year, dates[i].month, dates[i].day);
}

