#include "merge.h"
 
#include <stdlib.h>
#include <stdio.h>
 
Node *merge(Node *list[], int K) {
  Node *head = NULL, *cur; 
  int order = 1;
  while (1) {
    int ok = 1;
    for (int i = order ? 0 : (K - 1); (order && i < K) || (!order && i >= 0); order ? (++i) : (--i)) {
      if (list[i] != NULL) {
        ok = 0;
        if (head == NULL) {
          head = cur = list[i]; 
          list[i] = list[i]->next;
#ifdef DEBUG
          printf("%d\n", cur->data);
#endif
 
        } else {
          cur->next = list[i];
          list[i] = list[i]->next;
          cur = cur->next;
 
#ifdef DEBUG
          printf("%d\n", cur->data);
#endif
        }
 
      }
    }
    if (ok) break;
    order = !order;
  }
  return head;
}
