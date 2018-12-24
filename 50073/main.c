#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[12];
  int wealth;
} Record;

int Cmp(const void *pa, const void *pb) {
  Record *a = (Record*)pa, *b = (Record*)pb;
  if (a->wealth == b->wealth) return strcmp(a->name, b->name);
  return a->wealth - b->wealth;
}

int main(int argc, char **argv) {
  FILE *in = fopen(argv[1], "rb"); 

#ifdef DEBUG
  printf("File name: %s\n", argv[1]);
#endif

  Record records[1030];
  int n = 0;
  while (fread(records[n].name, 12, sizeof(char), in) != 0)
    fread(&records[n++].wealth, 1, sizeof(int), in);

  qsort(records, n, sizeof(Record), Cmp);

#ifdef DEBUG
  printf("Read in %d\n", n);
  for (int i = 0; i < n; ++i)
    printf("%s %d\n", records[i].name, records[i].wealth);
#endif

  int cnt = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    int bucket = records[i].wealth / 1000;
    if (bucket == cur) ++cnt;
    else {
      if (cnt != 0) printf("%d\n", cnt);
      cnt = 1, cur = bucket;
    }
  }
  if (cnt != 0) printf("%d\n", cnt);
  printf("%s\n", records[0].name);
  int max = n - 1;
  while (max - 1 >= 0 && records[max - 1].wealth == records[max].wealth) --max;
  printf("%s\n", records[max].name);
  printf("%lld\n",
      (n % 2 == 0) ? (((long long)records[n / 2 - 1].wealth + records[n / 2].wealth) / 2) : (long long)records[n / 2].wealth);

  fclose(in);
}

