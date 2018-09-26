#include "componentPart.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int calced[64] = {0};

int GetPrice(ComponentPart list[], int idx) {
  ComponentPart component = list[idx];
  if (calced[idx] || component.numComponent == 0) return component.price;
  int total = 0;
  for (int i = 0; i < component.numComponent; ++i)
    total += GetPrice(list, component.componentPartList[i]);
  list[idx].price = total;
  calced[idx] = 1;
  return total;
}

int comp(const void *a, const void *b) {
  return strcmp(((ComponentPart*)a)->name, ((ComponentPart*)b)->name);
}

void findPrice(int N,ComponentPart list[]) {
  for (int i = 0; i < N; ++i) GetPrice(list, i);

  qsort(list, N, sizeof(ComponentPart), comp);
  for (int i = 0; i < N; ++i)
    printf("%s %d\n", list[i].name, list[i].price);
}
