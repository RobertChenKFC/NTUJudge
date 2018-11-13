#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char name[35];
  int val;
  struct Node *left, *right;
} Node;

Node* Insert(Node *root, char *name, int val) {
  if (root == NULL) {
    root = malloc(sizeof(Node));
    strcpy(root->name, name);
    root->val = val;
    root->left = root->right = NULL;
    return root;
  }
  int cmp = strcmp(root->name, name);
  if (cmp < 0) root->left = Insert(root->left, name, val);
  else root->right = Insert(root->right, name, val);
  return root;
}

int Find(Node *root, char *name, int len) {
  int cmp = strncmp(root->name, name, len);
  if (cmp < 0) return Find(root->left, name, len);
  if (cmp > 0) return Find(root->right, name, len);
  return root->val;
}

#ifdef DEBUG
void PrintTree(Node *root) {
  if (root == NULL) return;
  PrintTree(root->left);
  printf("%s = %d\n", root->name, root->val);
  PrintTree(root->right);
}
#endif

#define IS_CHAR(X) (((X) >= 'a' && (X) <= 'z') || ((X) >= 'A' && (X) <= 'Z') || (X) == '_' || (X) == '$')
#define IS_DIGIT(X) ((X) >= '0' && (X) <= '9')

int ToInt(char *str, int len) {
  int ret = 0;
  for (int i = 0; i < len; ++i)
    ret = ret * 10 + str[i] - '0'; 
  return ret;
}

#ifdef DEBUG
void PrintExpression(char *expression, int len) {
  for (int i = 0; i < len && expression[i] != '\n'; ++i)
    printf("%c", expression[i]); 
}
#endif

int Parse(char *expression, int len, Node *root) {
#ifdef DEBUG
  printf("current expression (length %d): ", len);
  PrintExpression(expression, len);
  printf("\n");
#endif
  
  int validNumber = 1, validName = 1;
  for (int i = 0; i < len && (validNumber || validName); ++i) {
    char c = expression[i];
    if (i == 0) {
      if (!IS_CHAR(c)) validName = 0;
    } else {
      if (!(IS_CHAR(c) || IS_DIGIT(c))) validName = 0;
    }
    if (!IS_DIGIT(c)) validNumber = 0;
  }  
  if (validNumber) {
#ifdef DEBUG
    printf("current expression is a number: %d\n", ToInt(expression, len));
#endif
    return ToInt(expression, len);
  }
  if (validName) {
#ifdef DEBUG
    printf("current expression is a variable: %d\n", Find(root, expression, len));
#endif
    return Find(root, expression, len);
  }

  // (operator left-tree right-tree)
  char *cur = expression;
  while (*cur == ' ') ++cur;
  if (*cur == '(') ++cur;
  while (*cur == ' ') ++cur;
  char operator = *(cur++);

#ifdef DEBUG
  printf("operator is %c\n", operator);
#endif

  while (*cur == ' ') ++cur;
  char *leftBegin = cur, *leftEnd = leftBegin;
  int leftLen = 0;
  if (*leftBegin == '(') {
    leftEnd = ++leftBegin;
    int lefts = 1;
    while (lefts) {
      if (*leftEnd == '(') ++lefts;
      else if (*leftEnd == ')') --lefts;
      ++leftEnd;
    }
    --leftEnd;
  } else {
    while (*leftEnd != ' ') ++leftEnd;
  }
  leftLen = leftEnd - leftBegin;

  ++leftEnd;
  while (*leftEnd == ' ') ++leftEnd;
  char *rightBegin = leftEnd, *rightEnd = rightBegin;
  int rightLen = 0;
  if (*rightBegin == '(') {
    rightEnd = ++rightBegin;
    int lefts = 1;
    while (lefts) {
      if (*rightEnd == '(') ++lefts;
      else if (*rightEnd == ')') --lefts;
      ++rightEnd;
    }
    --rightEnd;
    rightLen = rightEnd - rightBegin;
  } else {
    rightEnd = expression + len - 1;
    while (*rightEnd == ' ') --rightEnd;
    if (*rightEnd == ')') --rightEnd;
    while (*rightEnd == ' ') --rightEnd;
    rightLen = rightEnd - rightBegin + 1;
  }

  int ret;
  switch (operator) {
  case '+':
    ret = Parse(leftBegin, leftLen, root) + Parse(rightBegin, rightLen, root);
    break;
  case '-':
    ret =  Parse(leftBegin, leftLen, root) - Parse(rightBegin, rightLen, root);
    break;
  case '*':
    ret =  Parse(leftBegin, leftLen, root) * Parse(rightBegin, rightLen, root);
    break;
  case '/':
    ret =  Parse(leftBegin, leftLen, root) / Parse(rightBegin, rightLen, root);
    break;
  default:
    ret =  -1;
    break;
  }
#ifdef DEBUG
  PrintExpression(expression, len);
  printf(" = %d\n", ret);
#endif
  return ret;
}

int main() {
  char expression[1005];
  fgets(expression, sizeof(expression), stdin);
  int len = strlen(expression) - 1;
  expression[len] = '\0';

  int n;
  char name[35];
  int val;
  Node *root = NULL;   
  while (scanf("%s", name) != EOF) {
    char buf;
    scanf(" %c%d", &buf, &val);

#ifdef DEBUG
    printf("buffer contains: %c, val contains: %d\n", buf, val);
#endif

    root = Insert(root, name, val);
  }

#ifdef DEBUG
  printf("all variables: \n");
  PrintTree(root);
  printf("\n");
#endif

  printf("%d\n", Parse(expression, len, root));
}

