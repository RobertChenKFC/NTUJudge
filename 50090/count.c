#include "count.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *ptr;
  int cnt;
  int val;
} Count;

int comp(const void *pa, const void *pb) {
  Count a = *(Count*)pa, b = *(Count*)pb;
  if (a.cnt == b.cnt)
    return a.val - b.val;
  return a.cnt - b.cnt;
}

void count(int **p[]) {
  Count counts[512];
  memset(counts, 0, sizeof(counts));
  int nCount = 0;
  for (int i = 0; i < 512; ++i) {
    int **p1 = p[i];
    if (p1 == NULL)
      break;
    int *p2 = *p1;
    for (int j = 0; j < 512; ++j) {
      if (counts[j].ptr == p2) {
        ++counts[j].cnt;
        break;
      } else if (counts[j].ptr == NULL) {
        ++nCount;
        ++counts[j].cnt; 
        counts[j].ptr = p2;
        counts[j].val = *p2;
        break;
      }
    }
  }
  qsort(counts, nCount, sizeof(Count), comp);
  for (int i = 0; i < nCount; ++i)
    printf("%d %d\n", counts[i].val, counts[i].cnt);
}
