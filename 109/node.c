#include "node.h"

#include <stdio.h>

int path[1000];
void Path(struct node *root, int len) {
  path[len - 1] = root->data;
  if (root->left == NULL && root->right == NULL) {
    for (int i = 0; i < len; ++i) {
      if (i != 0) printf(" ");
      printf("%d", path[i]);
    }
    printf("\n");
    return;
  }
  if (root->left != NULL) Path(root->left, len + 1);
  if (root->right != NULL) Path(root->right, len + 1);
}

void print_all_paths(struct node *root) {
  Path(root, 1);
}
 
