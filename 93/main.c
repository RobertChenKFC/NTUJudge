#include "heap.h"

#include <stdio.h>

#ifdef DEBUG
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
  return *((int*)b) - *((int*)a); 
}

void PrintHeap(struct Heap *heap) {
  int buf[MAXHEAP];
  memcpy(buf, heap->ary, sizeof(buf));
  qsort(buf, heap->num, sizeof(int), cmp);
  for (int i = 0; i < heap->num; ++i)
    printf("%d ", buf[i]);
} 
#endif

typedef struct Heap Heap;

int main() {
  Heap heap[1000];
  int idx;
  while (scanf("%d", &idx) != EOF) {
    int cmd;
    scanf("%d", &cmd);
    int n;
    switch (cmd) {
    case 0:
      initialize(&heap[idx]);
      printf("init\n");
      break;
    case 1:
#ifdef DEBUG
      PrintHeap(&heap[idx]);
#endif
      printf(", min: %d\n", removeMin(&heap[idx]));
      break;
    case 2:
      scanf("%d", &n);
      add(&heap[idx], n);
      printf("add %d\n", n);
      break;
    case 3:
      printf("%d\n", isFull(&heap[idx]));
      break;
    case 4:
      printf("%d\n", isEmpty(&heap[idx]));
      break;
    }
  }
}
