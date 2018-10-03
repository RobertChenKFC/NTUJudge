#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[16];
  int citations;
} Paper;

Paper papers[20000];

int Comp(const void *pa, const void *pb) {
  Paper *a = (Paper*)pa, *b = (Paper*)pb;
  int comp = strcmp(a->name, b->name);
  if (comp == 0) return b->citations - a->citations;
  return comp;
}

int main() {
  int n = 0;
  while (scanf("%s", papers[n].name) != EOF) {
    scanf("%d", &papers[n].citations);
    ++n; 
  }

  qsort(papers, n, sizeof(Paper), Comp);

  char *prev = papers[0].name;
  int hidx = papers[0].citations >= 1;
  for (int i = 1; i < n; ++i) {
    if (strcmp(papers[i].name, prev) != 0) {
      printf("%s %d\n", prev, hidx);
      prev = papers[i].name;
      hidx = papers[i].citations >= 1;
    } else {
      hidx += papers[i].citations >= hidx + 1;
    }
  }
  printf("%s %d\n", prev, hidx);
}

