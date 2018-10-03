#include "construct.h"

#include <stdlib.h>

typedef struct {
  int value;
  int pos;
} Element;
Element buf[16384];

int Comp(const void *pa, const void *pb) {
  Element *a = (Element*)pa, *b = (Element*)pb;
  return b->value - a->value;
}

int FindHead(int s[], int N) {
  for (int i = 0; i < N; ++i) {
    buf[i].value = s[i];
    buf[i].pos = i;
  } 
  qsort(buf, N, sizeof(Element), Comp);
  return buf[MAXLENGTH - 1].pos;
}

Node *ConstructTree(int s[], int N) {
  if (N == 0) return NULL;
  if (N < MAXLENGTH) {
    Node *cur = malloc(sizeof(Node));
    cur->value = s[N - 1]; 
    cur->right = NULL;
    cur->left = ConstructTree(s, N - 1);
    return cur; 
  }

  int headPos = FindHead(s, N);
  Node *head = malloc(sizeof(Node));
  head->value = s[headPos];
  head->left = ConstructTree(s, headPos);
  head->right = ConstructTree(s + headPos + 1, N - headPos - 1);
  return head;
}

