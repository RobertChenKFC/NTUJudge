#include "construct.h"

#include <stdio.h>
#include <stdlib.h>

Node* Construct(int weights[], int from, int to, int tree) {
  if (from > to) return NULL;
  int pivot = -1;
  if (tree && to - from >= 2) {
    for (int i = from; i <= to; ++i) {
      long long torque = 0;
      for (int j = from; j <= to; ++j)
        torque += (j - i) * weights[j]; 
      if (torque == 0) {
        pivot = i;
        break;
      }
    }
  }
  Node *node = malloc(sizeof(Node));
  if (pivot != -1) {
    node->value = weights[pivot];
    node->left = Construct(weights, from, pivot - 1, 1);
    node->right = Construct(weights, pivot + 1, to, 1);
  } else {
    node->value = weights[to];
    node->left = Construct(weights, from, to - 1, 0);
    node->right = NULL;
  }
  return node;
}

Node *ConstructTree(int T[], int N) {
  return Construct(T, 0, N - 1, 1);
}

