#include <stdio.h>
#include <string.h>

int in[15];
int no[15][15];
int perm[15];
int n;
void Perm(int idx) {
  if (idx >= n) {
    for (int i = 0; i < n; ++i)
      putchar('A' + perm[i]);
    putchar('\n');
  }
  for (int i = 0; i < n; ++i) {
    if (!in[i] && !no[i][idx]) {
      in[i] = 1;
      perm[idx] = i;
      Perm(idx + 1);
      in[i] = 0;
    } 
  }
}

int main() {
  int m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(in, 0, sizeof(in));
    memset(no, 0, sizeof(no));
    while (m--) {
      int id, pos;
      scanf("%d%d", &id, &pos);
      no[id - 1][pos - 1] = 1;
    }
    Perm(0);
  }
}

