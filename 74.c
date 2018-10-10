#include <stdio.h>

int main() {
  int mod[200000] = {0};
  int xs[200000];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &xs[i]);   
  int m;
  scanf("%d", &m);
  for (int i = 0; i < n; ++i)
    ++mod[xs[i] % m];
  for (int i = 0; i < m; ++i)
    printf("%d\n", mod[i]);
}

