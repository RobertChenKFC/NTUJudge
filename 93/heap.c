#include "heap.h" 

#include <string.h>
#include <stdio.h>

void initialize(struct Heap *heap) {
  memset(heap->ary, 0, sizeof(int) * MAXHEAP); 
  heap->num = 0;
}

int removeMin(struct Heap *heap) {
  int top = heap->ary[0];
  heap->ary[0] = heap->ary[heap->num - 1];
  --heap->num;
  int cur = 0;
  while (cur < heap->num) {
    int left = cur * 2 + 1, right = left + 1;
    if (left >= heap->num) left = cur;
    if (right >= heap->num) right = cur;
    int min = heap->ary[left] < heap->ary[right] ? left : right;
    if (heap->ary[cur] > heap->ary[min]) {
      int t = heap->ary[cur];
      heap->ary[cur] = heap->ary[min];
      heap->ary[min] = t;
      cur = min;
    } else {
      break; 
    }
  }
  return top;
}

void add(struct Heap *heap, int i) {
  heap->ary[heap->num] = i;
  int child = heap->num;
  int parent = (child - 1) / 2;
  while (parent >= 0) {
    if (heap->ary[parent] > heap->ary[child]) {
      int t = heap->ary[parent];
      heap->ary[parent] = heap->ary[child];
      heap->ary[child] = t;
    } else {
      break; 
    }
    child = parent;
    parent = (child - 1) / 2;
  }
  ++heap->num;
}

int isFull(struct Heap *heap) {
  return heap->num == MAXHEAP;
}

int isEmpty(struct Heap *heap) {
  return heap->num == 0;
}
