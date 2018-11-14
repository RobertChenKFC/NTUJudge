#include "node.h"

#include <stdio.h>

struct node *getNode(struct node *head, unsigned int i);
typedef struct node Node;

int main() {
  Node nodes[5];
  for (int i = 0; i < 4; ++i)
    nodes[i].next = &nodes[i + 1];
  nodes[4].next = NULL;

  for (int i = 0; i < 6; ++i) {
    Node *ret = getNode(&nodes[0], i);
    printf("Asking for the %dth item, returned ", i);
    if (ret == NULL) printf("NULL\n");
    else printf("%d\n", (int)(ret - &nodes[0]));
  }
}
