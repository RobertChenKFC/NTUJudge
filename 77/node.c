#include "node.h"

#include <stdio.h>

struct node *getNode(struct node *head, unsigned int i) {
  unsigned int n = 0;
  struct node *cur = head;
  while (cur != NULL) {
    cur = cur->next;
    ++n;
  }

#ifdef DEBUG
  printf("Requesting %d from %d items, actual index %d\n", i, n, n - 1 - i);
#endif

  if (i > n) return NULL;
  i = n - 1 - i;

  cur = head;
  while (cur != NULL && i != 0) {
    cur = cur->next; 
    --i;
  }
  return cur;
}

