#include <stdio.h>

char map[1001][1001] = {0};
int n;
int cycle[1001];
char inCycle[1001] = {0};

char FindCycle(int head, int cur, int found) {
  if (found == n && map[cur][head]) {
    cycle[found] = head;
    return 1;
  }

  inCycle[cur] = 1;
  for (int i = 0; i < n; ++i) {
    if (!inCycle[i] && map[cur][i] && FindCycle(head, i, found + 1)) {
      cycle[found] = i;
      return 1;
    }
  }
  inCycle[cur] = 0;
  return 0;
}

int main() {
  int e;
  scanf("%d%d", &n, &e);
  int x, y;
  while (e--) {
    scanf("%d%d", &x, &y);
    map[x][y] = map[y][x] = 1;
  }

  char cycleFound = 0;
  for (int i = 0; i < n; ++i) {
    if (FindCycle(i, i, 1)) {
      cycleFound = 1;
      break;
    }
  }

  if (cycleFound) {
    for (int i = 0; i <= n; ++i) {
      if (i != 0) printf(" ");
      printf("%d", cycle[i]);
    }
    printf("\n");
  } else {
    printf("NO SOLUTION\n");
  }
}

