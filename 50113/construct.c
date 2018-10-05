#include "construct.h"

#include <stdlib.h>

void Insert(Node *node, int val) {
  if (node->large == -1) {
    node->large = val;
  } else if (node->small == -1) {
    if (val < node->large) {
      node->small = val; 
    } else {
      int t = node->large;
      node->large = val;
      node->small = t;
    }
  } else {
    if (val < node->small) {
      if (node->left == NULL) {
        node->left = malloc(sizeof(Node));
        node->left->left = node->left->right = NULL;
        node->left->small = node->left->large = -1;
      } 
      Insert(node->left, val);
    } else if (val > node->large) {
      if (node->right == NULL) {
        node->right = malloc(sizeof(Node));
        node->right->left = node->right->right = NULL;
        node->right->small = node->right->large = -1;
      }
      Insert(node->right, val);
    } else {
      if (node->mid == NULL) {
        node->mid = malloc(sizeof(Node));
        node->mid->left = node->mid->right = NULL;
        node->mid->small = node->mid->large = -1;
      }
      Insert(node->mid, val);
    }
  }
}

Node* ConstructTree(int s[], int N) {
  Node *node = malloc(sizeof(Node));
  node->left = node->mid = node->right = NULL;
  node->small = node->large = -1;
  for (int i = 0; i < N; ++i)
    Insert(node, s[i]);
  return node;
}
