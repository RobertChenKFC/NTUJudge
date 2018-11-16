#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string_count {
  char seen[80];
  int count;
};
int n = 0;

int compare_and_add(char *string, struct string_count strings[]) {
  for (int i = 0; i < n; ++i) {
    if (strcmp(string, strings[i].seen) == 0) {
      ++strings[i].count;
      return 1;
    } 
  } 
  strcpy(strings[n].seen, string);
  strings[n].count = 1;
  ++n;
  return 0;
}

int Cmp(const void *pa, const void *pb) {
  struct string_count *a = (struct string_count*)pa, *b = (struct string_count*)pb;
  if (a->count == b->count) return strcmp(a->seen, b->seen);
  return a->count - b->count;
}

void sort(struct string_count strings[]) {
  qsort(strings, n, sizeof(struct string_count), Cmp);
}

void print(struct string_count strings[]) {
  for (int i = 0; i < n; ++i)
    printf("%d %s\n", strings[i].count, strings[i].seen);
}

