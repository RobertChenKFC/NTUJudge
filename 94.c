#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int val;
  struct Node *left, *right;
} Node;

Node* CreateTree(char *str, int len) {
  ++str;
  len -= 2;
#ifdef DEBUG
  printf("Create tree from: ");
  for (int i = 0; i < len; ++i)
    printf("%c", str[i]);
  printf(" (len: %d)\n", len);
#endif

  int i = 0;
  Node *left;
  if (str[i] == '(') {
    ++i;
    int brackets = 1;
    while (brackets != 0) {
      if (str[i] == '(') ++brackets;
      else if (str[i] == ')') --brackets;
      ++i;
    }
    left = CreateTree(str, i);
  } else {
    int num = 0;
    while (str[i] != ',') {
      num = num * 10 + str[i] - '0';
      ++i;
    }
    left = malloc(sizeof(Node));
    left->val = num;
    left->left = left->right = NULL;
  }

  str += i + 1;
  len -= i + 1;
  i = 0;

  Node *right;
  if (str[i] == '(') {
    ++i;
    int brackets = 1;
    while (brackets != 0) {
      if (str[i] == '(') ++brackets;
      else if (str[i] == ')') --brackets;
      ++i;
    }
    right = CreateTree(str, i);
  } else {
    int num = 0;
    while (i < len) {
      num = num * 10 + str[i] - '0';
      ++i;
    }
    right = malloc(sizeof(Node));
    right->val = num;
    right->left = right->right = NULL;
  }

  Node *mid = malloc(sizeof(Node));
  mid->val = left->val + right->val;
  mid->left = left, mid->right = right;
#ifdef DEBUG
  printf("left is %d, right is %d, mid is %d\n", mid->left->val, mid->right->val, mid->val);
#endif
  return mid;
}

#ifdef DEBUG
void PrintTree(Node *root) {
  if (root == NULL) return;
  PrintTree(root->left);
  printf("%d\n", root->val);
  PrintTree(root->right);
}
#endif

void HRHL(Node *root);
void HLHR(Node *root) {
  if (root == NULL) return;
  printf("%d\n", root->val);
  HRHL(root->left);
  printf("%d\n", root->val);
  HRHL(root->right);
}
void HRHL(Node *root) {
  if (root == NULL) return;
  printf("%d\n", root->val);
  HLHR(root->right);
  printf("%d\n", root->val);
  HLHR(root->left);
}

int main() {
  char str[4005];
  scanf("%s", str);
  Node *root = CreateTree(str, strlen(str));

#ifdef DEBUG
  printf("Full tree:\n");
  PrintTree(root);
  printf("\n");
#endif

  HLHR(root);
}

