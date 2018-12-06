#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
  if (n == 0) {
    printf("\n");
    return NULL;
  }
  Node *head = malloc(sizeof(Node));
  head->v = sp_rand();
  printf("%d -> ", head->v);
  head->next = mk_list(n - 1);
  return head;
}
void rm_list(Node *head) {
  if (head == NULL) return;
  rm_list(head->next);
  free(head);
}
