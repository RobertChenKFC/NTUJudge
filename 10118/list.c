#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
  if (n == 0) return NULL;
  Node *prev = malloc(sizeof(Node)), *cur;
  Node *head = prev;
  prev->v = sp_rand(), prev->next = NULL;
  for (int i = 1; i < n; ++i) {
    cur = malloc(sizeof(Node)); 
    cur->v = sp_rand(), cur->next = NULL;
    prev->next = cur, prev = cur;
  }
  return head;
}

void rm_list(Node *head) {
  Node *cur = head;
  while (cur != NULL) {
    Node *next = cur->next;
    free(cur);
    cur = next;
  }
}
