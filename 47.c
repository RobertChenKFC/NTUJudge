#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
  int from;
  int to;
  char c;
  struct Node *left;
  struct Node *right;
} Node;

void Add(Node *node, int inc) {
  if (node == NULL) return;
  node->from += inc;
  node->to += inc;
  Add(node->left, inc);
  Add(node->right, inc);
}

Node* InsertRight(Node *node, char c, int n) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->from = 0;
    node->to = n - 1;
    node->c = c;
    node->left = node->right = NULL;
    return node;
  }

  Node *root = node;
  while (node->left != NULL || node->right != NULL)
    node = node->right; 
  if (node->c == c) {
    node->to += n;
  } else {
    node->right= malloc(sizeof(Node)); 
    node->right->from = node->to + 1;
    node->right->to = node->to + n;
    node->right->c = c;
    node->right->left = node->right->right = NULL;
  }
  return root;
}

Node* Insert(Node *node, char c, int from, int to) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->from = from;
    node->to = to;
    node->c = c;
    node->left = node->right = NULL;
    return node;
  }

  if (node->c == c && (node->from == to + 1 || node->to == from - 1)) {
    int inc = to - from + 1;
    node->to += inc;
    Add(node->right, inc);
  } else if (from < node->from) {
    node->left = Insert(node->left, c, from, to);
  } else if (from > node->to) {
    node->right = Insert(node->right, c, from, to);
  } else if (node->c == c) {
    int inc = to - from + 1;
    node->to += inc;
    Add(node->right, inc);
  } else {
    Node *leftMost = node->left;
    Node *rightMost = node->right;
    if (from - 1 >= node->from) {
      Node *left = malloc(sizeof(Node));
      left->from = node->from;
      left->to = from - 1;
      left->c = node->c;
      left->left = leftMost;
      left->right = NULL;
      node->left = left;
    }
    if (node->to >= from) {
      Node *right = malloc(sizeof(Node));
      right->from = from;
      right->to = node->to;
      right->c = node->c;
      right->left = NULL;
      right->right = rightMost;
      node->right = right;
      Add(node->right, to - from + 1);
    }
    node->from = from;
    node->to = to;
    node->c = c;
  }
  return node;
}

void Print(Node *node) {
  if (node == NULL) return;
  Print(node->left);
  printf("%c %d ", node->c, node->to - node->from + 1);
  Print(node->right);
}

int main() {
  char instruction[10];
  Node *root = NULL;
  while (scanf("%s", instruction) != EOF) {
    if (strcmp(instruction, "print") == 0) {
      Print(root);
      printf("$\n");
    } else if (strcmp(instruction, "insert") == 0) {
      char c;
      int n;
      scanf("%s %c%d", instruction, &c, &n);
      if (strcmp(instruction, "left") == 0) {
        root = Insert(root, c, 0, n - 1);

#ifdef DEBUG
        printf("After inserting %c from %d to %d: ", c, 0, n - 1);
        Print(root);
        printf("$\n");
#endif
      } else if (strcmp(instruction, "right") == 0) {
        root = InsertRight(root, c, n); 

#ifdef DEBUG
        printf("After inserting %d %c from the right: ", n, c);
        Print(root);
        printf("$\n");
#endif
      } else {
        int k = atoi(instruction); 
        root = Insert(root, c, k - 1, k + n - 2);

#ifdef DEBUG
        printf("After inserting %c from %d to %d: ", c, k - 1, k + n - 2);
        Print(root);
        printf("$\n");
#endif
      }
    }
  }
}

