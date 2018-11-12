#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int key;
  int level;
} Datum;

typedef struct Node {
  int key;
  struct Node *parent;
  struct Node *left, *right;
} Node;

Node* Insert(Node *root, int key) {
  if (root == NULL) {
    root = malloc(sizeof(Node)); 
    root->key = key;
    root->parent = NULL;
    root->left = root->right = NULL;
  }
  if (key < root->key) {
    root->left = Insert(root->left, key);
    root->left->parent = root;
  }
  if (key > root->key) {
    root->right = Insert(root->right, key);
    root->right->parent = root;
  }
  return root;
}

Node* Find(Node *root, int key) {
  if (key < root->key) return Find(root->left, key);
  if (key > root->key) return Find(root->right, key);
  return root;
}

int FindAllParents(Node *root, Node **parents) {
  Node *cur = root;
  int nParents = 0;
  while (cur != NULL) {
    parents[nParents++] = cur;
    cur = cur->parent; 
  }
  return nParents;
}

int Distance(Node *a, Node *b) {
  Node *parentsA[1005];
  Node *parentsB[1005];
  int nParentsA = FindAllParents(a, parentsA);
  int nParentsB = FindAllParents(b, parentsB);

#ifdef DEBUG
  printf("%d's parents: \n", a->key);
  for (int i = 0; i < nParentsA; ++i)
    printf("%d ", parentsA[i]->key);
  printf("END\n%d's parents: \n", b->key);
  for (int i = 0; i < nParentsB; ++i)
    printf("%d ", parentsB[i]->key);
  printf("END\n");
#endif
 
  if (nParentsA == 1) return nParentsB - 1;
  if (nParentsB == 1) return nParentsA - 1;
  for (int i = 0; i < nParentsA; ++i) {
    for (int j = 0; j < nParentsB; ++j)
      if (parentsA[i] == parentsB[j]) return i + j; 
  }
  return -1;
}

#ifdef DEBUG
void PrintTree(Node *root) {
  if (root == NULL) return;
  PrintTree(root->left);
  printf("%d (parent: %d)\n", root->key, root->parent ? root->parent->key : -1);
  PrintTree(root->right);
}
#endif

int Cmp(const void *pa, const void *pb) {
  Datum *a = (Datum*)pa, *b = (Datum*)pb;
  if (a->level == b->level) return a->key - b->key;
  return a->level -  b->level;
}

int main() {
  Datum data[1005];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &data[i].key, &data[i].level);
  qsort(data, n, sizeof(Datum), Cmp);

#ifdef DEBUG
  printf("Sorted data: \n");
  for (int i = 0; i < n; ++i)
    printf("%d %d\n", data[i].key, data[i].level);
  printf("\n");
#endif

  Node *root = NULL;
  for (int i = 0; i < n; ++i)
    root = Insert(root, data[i].key);

#ifdef DEBUG
  printf("Whole tree: \n");
  PrintTree(root);
  printf("\n");
#endif

  scanf("%d", &n);
  while (n--) {
    int keya, keyb;
    scanf("%d%d", &keya, &keyb);
    printf("%d\n", Distance(Find(root, keya), Find(root, keyb)));
  }
}

