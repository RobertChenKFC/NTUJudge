#include "operations.h"

#include <stdio.h>
#include <stdlib.h>

Node *FlipTree(Node *root) {
  if (root == NULL) return NULL;
  Node *node = malloc(sizeof(Node));
  node->n = root->n;
  node->left = FlipTree(root->right);
  node->right = FlipTree(root->left);
  return node;
}

int isIdentical(Node *tree1, Node *tree2) {
  if (tree1 == NULL && tree2 == NULL) return 1;
  if (tree1 == NULL || tree2 == NULL || tree1->n != tree2->n) return 0;
  return isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
}

int depthSum;
int numLeaves;

void calcDepth(Node *root, int depth) {
  if (root->left == NULL && root->right == NULL) {
    depthSum += depth;
    ++numLeaves;
    return;
  }
  if (root->left != NULL) calcDepth(root->left, depth + 1);
  if (root->right != NULL) calcDepth(root->right, depth + 1);
}

void depthAvg(Node *root) {
  depthSum = numLeaves = 0; 
  calcDepth(root, 0);
  printf("%d/%d\n", depthSum, numLeaves);
}

