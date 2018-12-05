#include "pangfeng.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *sortOrder;
int nScores;
int Cmp(const void *pa, const void *pb) {
  Row *a = (Row*)pa, *b = (Row*)pb;
  for (int i = 0; i < nScores; ++i) {
    if (a->scores[sortOrder[i]] < b->scores[sortOrder[i]]) return 1;
    if (a->scores[sortOrder[i]] > b->scores[sortOrder[i]]) return -1;
  }
  return strcmp(a->name, b->name);
}

void init(ExamTable *self, int n) {
  self->dim_n = n;
  self->idx = 0;
}

void addrow(ExamTable *self, char *name, int score[]) {
  strcpy(self->rows[self->idx].name, name);
  self->rows[self->idx].scores = malloc(sizeof(int) * self->dim_n);
  for (int i = 0; i < self->dim_n; ++i)
    self->rows[self->idx].scores[i] = score[i];
  ++self->idx;
}

void print(ExamTable *self, int order[]) {
  sortOrder = order;
  nScores = self->dim_n;
  qsort(self->rows, self->idx, sizeof(Row), Cmp);

  printf("----- table begin -----\n");
  for (int i = 0; i < self->idx; ++i) { 
    printf("%s", self->rows[i].name);
    for (int j = 0; j < self->dim_n; ++j)
      printf(", %d", self->rows[i].scores[j]);
    printf("\n");
  }
  printf("----- end         -----\n");
}

