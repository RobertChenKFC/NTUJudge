#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  unsigned int id;
  char name[32];
} Person;

typedef struct {
  unsigned id1;
  unsigned id2;
} Friends;

typedef struct Node {
  unsigned int id;
  char name[32]; 
  struct Node *left, *right;
} Node;

Node* PersonToNode(Person *person) {
  Node *node = malloc(sizeof(Node));
  node->id = person->id;
  strcpy(node->name, person->name);
  node->left = node->right = NULL;
  return node;
}

void Insert(Node *root, Node *node) {
  if (strcmp(node->name, root->name) < 0) {
    if (root->left != NULL) Insert(root->left, node); 
    else root->left = node;
  } else {
    if (root->right != NULL) Insert(root->right, node);
    else root->right = node;
  }
}

unsigned int GetID(Node *root, char *name) {
  int cmp = strcmp(name, root->name);
  if (cmp < 0) return GetID(root->left, name);
  if (cmp > 0) return GetID(root->right, name);
  return root->id;
}

#ifdef DEBUG
void PrintTree(Node *root) {
  if (root == NULL) return;
  PrintTree(root->left);
  printf("%s %d\n", root->name, root->id);
  PrintTree(root->right);
}
#endif

int main() {
  FILE *in = fopen("friends", "rb");

  int nPeople;
  fread(&nPeople, sizeof(nPeople), 1, in);
  Node *root = NULL;
  Person person;
  for (int i = 0; i < nPeople; ++i) {
    fread(&person, sizeof(Person), 1, in);
    if (root == NULL) root = PersonToNode(&person);
    else Insert(root, PersonToNode(&person));
  }

#ifdef DEBUG
  printf("Whole tree: \n");
  PrintTree(root);
#endif

  int nFriends;
  Friends friends[10000];
  fread(&nFriends, sizeof(nFriends), 1, in);
  fread(friends, sizeof(Friends), nFriends, in);

#ifdef DEBUG
  printf("All friends: \n");
  for (int i = 0; i < nFriends; ++i)
    printf("%d %d\n", friends[i].id1, friends[i].id2); 
#endif

  char name1[32], name2[32];
  while (scanf("%s%s", name1, name2) != EOF) {
    if (strcmp(name1, "end") == 0) break;
#ifdef DEBUG
    printf("Checking if \"%s\" and \"%s\" are friends\n", name1, name2); 
#endif
    int id1 = GetID(root, name1);
    int id2 = GetID(root, name2);

#ifdef DEBUG
    printf("%s -> %d\n%s -> %d\n", name1, id1, name2, id2);
#endif

    int yes = 0;
    for (int i = 0; i < nFriends; ++i) {
      if ((id1 == friends[i].id1 && id2 == friends[i].id2) ||
          (id1 == friends[i].id2 && id2 == friends[i].id1)) {
        yes = 1; 
        break;
      }
    }
    if (yes) printf("yes\n");
    else printf("no\n");
  }

  fclose(in);
}

