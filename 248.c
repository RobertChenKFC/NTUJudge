#include <stdio.h>
#include <string.h>

int count[81];
int mine[81];

int Sum(int idx) {
#ifdef DEBUG
  printf("Summing %d\n", idx);
#endif

  int sum = 0;
  int r = idx / 9, c = idx % 9;
  for (int dr = -1; dr <= 1; ++dr) {
    for (int dc = -1; dc <= 1; ++dc) {
      int nr = r + dr, nc = c + dc;
      if (nr >= 0 && nr < 9 && nc >= 0 && nc < 9) {
        int i = nr * 9 + nc;

#ifdef DEBUG
        printf("Checking %d\n", i);
#endif

        if (mine[i] == -1) return -1;
        sum += mine[i];
      }
    } 
  }
  return sum;
}

int Fill(int idx) {
  for (int i = 0; i < idx; ++i) {
    int sum = Sum(i);
    if (sum != -1 && count[i] != sum) return 0;
  }
  if (idx == 81) return 1;
  mine[idx] = 0;
#ifdef DEBUG
  printf("Trying 0 for %d\n", idx);
#endif
  if (Fill(idx + 1)) return 1;
  mine[idx] = 1;
#ifdef DEBUG
  printf("Trying 1 for %d\n", idx);
#endif
  if (Fill(idx + 1)) return 1;
  mine[idx] = -1;
  return 0;
}

int main() {
  memset(mine, -1, sizeof(mine));
  for (int i = 0; i < 81; ++i)
    scanf("%d", &count[i]);

  if (Fill(0)) {
    int idx = 0;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (j != 0) printf(" ");
        printf("%d", mine[idx++]);
      } 
      printf("\n");
    }
  } else {
    printf("no solution\n");
  }

#ifdef DEBUG
  printf("After filling: \n");
  int idx = 0;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (j != 0) printf(" ");
      printf("%d", mine[idx++]);
    } 
    printf("\n");
  }
#endif
}

