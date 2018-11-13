#include "heap.h" 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  return *((int*)b) - *((int*)a);
}

void initialize(struct Heap *heap) {
  memset(heap->ary, 0, sizeof(int) * MAXHEAP); 
  heap->num = 0;
}

int removeMin(struct Heap *heap) {
  --heap->num;
  int top = heap->ary[heap->num];
  return top;
}

void add(struct Heap *heap, int i) {
  heap->ary[heap->num] = i;
  ++heap->num;
  qsort(heap->ary, heap->num, sizeof(int), Cmp);
}

int isFull(struct Heap *heap) {
  return heap->num == MAXHEAP;
}

int isEmpty(struct Heap *heap) {
  return heap->num == 0;
}
