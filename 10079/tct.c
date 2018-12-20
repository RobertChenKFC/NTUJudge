#include "tct.h"

#include <stdio.h>
#include <string.h>

char buf[1000000];
void PrintTree(Directory *dir, int cur, char *indent) {
  if (dir == NULL) return;
  Directory *x = dir;
  do {
    if (cur != 0) printf("%s|\n", indent);
    printf("%s+- %s\n", indent, x->name);
    indent[cur] = (cur == 0 || x->silbingDir == NULL) ? ' ' : '|';
    indent[cur + 1] = indent[cur + 2] = ' ';
    indent[cur + 3] = '\0';
    PrintTree(x->childDir, cur + 3, indent);
    indent[cur] = '\0';
    x = x->silbingDir;
  } while (x != NULL && cur != 0);
}

void tree(Directory *fs) {
  buf[0] = '\0';
  PrintTree(fs, 0, buf);
}

Directory* cd(Directory *fs, char path[]) {
  char *token = strtok(path, "/");
  Directory *dir = fs;
  while (token != NULL) {
    Directory *curDir = dir->childDir;
    while (strcmp(token, curDir->name) != 0)
      curDir = curDir->silbingDir; 
    dir = curDir;

#ifdef DEBUG
    printf("Current directory is %s\n", dir->name);
#endif

    token = strtok(NULL, "/");
  }
  return dir;
}

