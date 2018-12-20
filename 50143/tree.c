#include "tree.h"

#include <stdlib.h>
 
Node *treeAND(Node *root1, Node *root2) {
  if (root1 == NULL || root2 == NULL) return NULL;
  Node *root = malloc(sizeof(Node));
  root->val = root1->val * root2->val;
  root->left = treeAND(root1->left, root2->left);
  root->right = treeAND(root1->right, root2->right);
  return root;
}

Node *treeOR(Node *root1, Node *root2) {
  if (root1 == NULL && root2 == NULL) return NULL;
  Node *root = malloc(sizeof(Node));
  root->val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
  root->left = treeOR(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
  root->right = treeOR(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
  return root;
}

