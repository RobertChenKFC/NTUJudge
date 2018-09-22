#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[10000000];
char ***words; 
char word[1024];
char *line[16384];
int count[1024];

char scan() {
  char c = getchar();
  int i = 0;
  while (c != ' ' && c != '\n') {
    word[i++] = c; 
    c = getchar();
  }
  word[i] = '\0';
  return c;
}

int main() {
  char *cur = buf;
  int n;
  scanf("%d\n", &n);
  words = (char***)malloc(n * sizeof(char***));
  for (int i = 0; i < n; ++i) {
    count[i] = 0;
    while (1) {
      char end = scan();
      strcpy(cur, word);
      line[count[i]++] = cur;
      cur += strlen(word);
      *(cur++) = '\0';
      if (end == '\n')
        break;
    }
    words[i] = (char**)malloc(count[i] * sizeof(char**));
    for (int j = 0; j < count[i]; ++j)
      words[i][j] = line[j]; 
  }
  int ins;
  scanf("%d", &ins);
  while (ins--) {
    int i1, j1, i2, j2;
    scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
    char *t = words[i1][j1];
    words[i1][j1] = words[i2][j2];
    words[i2][j2] = t;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < count[i]; ++j) {
      if (j != 0) printf(" ");
      printf("%s", words[i][j]);
    }
    printf("\n");
  }
}
