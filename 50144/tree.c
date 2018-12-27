#include "tree.h"
 
#include <stdlib.h>
 
Node *construct(Node *root, char instruction[MAXN]) {
  if (root == NULL) {
    root = malloc(sizeof(Node));
    root->data = 1;
    root->left = root->right = NULL;
  } else {
    ++root->data; 
  }
  Node *cur = root;
  for (int i = 0; instruction[i] != '\0'; ++i) {
    if (instruction[i] == 'L') {
      if (root->left == NULL) {
        root->left = malloc(sizeof(Node));
        root->left->data = 1;
        root->left->left = root->left->right = NULL;
      } else ++root->left->data;
      root = root->left;
    } else {
      if (root->right == NULL) {
        root->right = malloc(sizeof(Node));
        root->right->data = 1;
        root->right->left = root->right->right = NULL;
      } else ++root->right->data;
      root = root->right;
    }
  }
  return cur;
}
 
int query(Node *root, char instruction[MAXN]) {
  for (int i = 0; instruction[i] != '\0' && root != NULL; ++i) {
    if (instruction[i] == 'L') root = root->left;
    else root = root->right;
  }
  if (root == NULL) return 0;
  return root->data;
}
