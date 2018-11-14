#include "node.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
void PrintList(struct node *list) {
  while (list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
}
#endif

struct node *merge(struct node *list1, struct node *list2) {
#ifdef DEBUG
  printf("List 1: ");
  PrintList(list1);
  printf("\nList 2: ");
  PrintList(list2);
  printf("\n\n");
#endif

  if (list1 == NULL && list2 == NULL) return NULL;
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;
  if (list1->value <= list2->value) {
    list1->next = merge(list1->next, list2);
    return list1;
  }
  list2->next = merge(list1, list2->next);
  return list2;
}

