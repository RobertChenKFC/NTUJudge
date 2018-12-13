#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
 
bstNode* bstNode_getLson(bstNode *self) {
    return self->lson;
} 
bstNode* bstNode_getRson(bstNode *self) {
    return self->rson;
}
void bstNode_setLson(bstNode *self, bstNode *u) {
    self->lson = u;
} 
void bstNode_setRson(bstNode *self, bstNode *u) {
    self->rson = u;
}
void bstNode_print(bstNode *self) {
    printf("%d ", *(int *)(self->extra));
}

int bstNode_init(bstNode *obj) {
    obj->getLson = bstNode_getLson;
    obj->getRson = bstNode_getRson;
    obj->setLson = bstNode_setLson;
    obj->setRson = bstNode_setRson;
    obj->print = bstNode_print;
    obj->extra = (void *) malloc(sizeof(int));
    return 1;
}

void bstNode_destroy(bstNode *obj) {
    free(obj->extra);
}
 
Object bstNodeProto = {
    .init = bstNode_init,
    .destroy = NULL
};

bstNode* Insert(bstNode *root, int *val) {
  if (root == NULL) {
    root = malloc(sizeof(bstNode));
    root->proto = bstNodeProto;
    bstNode_init(root);
    root->extra = val;
    root->lson = root->rson = NULL;
    return root;
  }
  if (*val < *((int*)root->extra))
    root->lson = Insert(root->lson, val);
  else if (*val > *((int*)root->extra))
    root->rson = Insert(root->rson, val);
  return root;
}
 
bstNode* buildBST(int A[], int n) {
  bstNode *root = NULL;
  for (int i = 0; i < n; ++i)
    root = Insert(root, &A[i]); 
  return root;
}
