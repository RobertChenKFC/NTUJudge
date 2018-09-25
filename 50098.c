#include <stdio.h>

int n, k;
int chosenClubs[101] = {0};
unsigned long long clubs[101] = {0};

int DisjointClubs(unsigned long long members, int cur, int chosen) {
  if (chosen == k) return 1;
  if (cur == n) return 0;
  if (!(members & clubs[cur]) && DisjointClubs(members | clubs[cur], cur + 1, chosen + 1)) {
    chosenClubs[chosen] = cur;
    return 1;
  }
  return DisjointClubs(members, cur + 1, chosen);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int members, member;
    scanf("%d", &members);
    while (members--) {
      scanf("%d", &member);
      clubs[i] |= 1ULL << member;
    }
  }
  DisjointClubs(0, 0, 0);
  for (int i = 0; i < k; ++i)
    printf("%d\n", chosenClubs[i]);
}
