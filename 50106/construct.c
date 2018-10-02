#include "construct.h"

#include <stdlib.h>
#include <string.h>
 
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]) {
  Node *node = malloc(sizeof(Node));
  strcpy(node->name, name[0]);
  node->height = height[0];
  node->weight = weight[0];
  node->left = node->right = NULL;
  for (int i = 1; i < N; ++i) {
    Node *root = node;
    while (1) {
#ifdef HEIGHT
      int val = height[i];
      int rootVal = root->height;
#endif
#ifdef WEIGHT
      int val = weight[i];
      int rootVal = root->weight;
#endif
      if (val < rootVal) {
        if (root->left == NULL) {
          root->left = malloc(sizeof(Node));
          strcpy(root->left->name, name[i]);
          root->left->height = height[i];
          root->left->weight = weight[i];
          break;
        } else {
          root = root->left; 
        }
      } else if (val > rootVal) {
        if (root->right == NULL) {
          root->right = malloc(sizeof(Node));
          strcpy(root->right->name, name[i]);
          root->right->height = height[i];
          root->right->weight = weight[i];
          break;
        } else {
          root = root->right; 
        }
      }
    }
  }
  return node;
}

