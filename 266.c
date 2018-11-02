#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int Min(int a, int b) {
  return a <= b ? a : b;
}

typedef struct {
  char s[15];
  int len;
  int id;
} Word;

int Dist(char *a, int lena, char *b, int lenb) {
  if (lena == 0) return lenb;
  if (lenb == 0) return lena;
  if (a[0] == b[0]) return Dist(a + 1, lena - 1, b + 1, lenb - 1);
  return 1 + Min(Dist(a + 1, lena - 1, b, lenb), Dist(a, lena, b + 1, lenb - 1));
}

int main() {
  Word words[105];
  int n = 0;
  while (scanf("%s", words[n++].s) != EOF);

  for (int i = 0; i < n; ++i) {
    words[i].len = strlen(words[i].s);
    words[i].id = i + 1; 
  }

  int min = INT_MAX;
  int mini, minj;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dist = Dist(words[i].s, words[i].len, words[j].s, words[j].len);
      if (dist < min) {
        mini = words[i].id;
        minj = words[j].id;
        min = dist;
      }
    }
  }
  printf("%d %d %d\n", min, mini, minj);
}
