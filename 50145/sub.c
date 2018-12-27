#include "sub.h"

#include <stdio.h>

void substring(Node* text, Node* pattern) {
  int idxStart = 0;
  for (Node *i = text; i != NULL; i = i->next) {
    int sum = 0, idx = idxStart;
    for (Node *j = i, *k = pattern; k != NULL; j = j->next, k = k->next) {
      sum += idx;

#ifdef DEBUG
      printf("Comparing %c to %c\n", j->c, k->c);
#endif

      if (j->c != k->c) {
        sum = -1;
        break;
      }
      ++idx;
    }
    if (sum != -1) {
      printf("%d\n", sum);
      break;
    }
    ++idxStart;
  }
}

void subsequence(Node* text, Node* pattern) {
  Node *i = text, *j = pattern;
  int idx = 0, sum = 0;
  while (i != NULL) {
    if (j == NULL) {
      printf("%d\n", sum);
      break;
    }

#ifdef DEBUG
      printf("Comparing %c to %c\n", i->c, j->c);
#endif

    if (i->c == j->c) {
      sum += idx;
      j = j->next;
    }
    i = i->next;
    ++idx;
  }
}

