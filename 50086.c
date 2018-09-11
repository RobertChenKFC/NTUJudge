#include <stdio.h>

int friends[32768][256];
int nFriends[32768] = {0};
char party[32768] = {0};
int main() {
  int n, e;
  scanf("%d%d", &n, &e);
  int a, b;
  while (e--) {
    scanf("%d%d", &a, &b);
    friends[a][nFriends[a]++] = b;
    friends[b][nFriends[b]++] = a;
  }
  while (scanf("%d", &a) != EOF) {
    party[a] = 1;
    for (int i = 0; i < nFriends[a]; ++i)
      party[friends[a][i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (!party[i])
      printf("%d\n", i);
  }
}
