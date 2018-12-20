#include <stdio.h>
#include <string.h>

int combos[105][105];
int scores[105];
int try[105];
int success[105];
int query[105];
int n, m;

#define NOT_SURE 2
#define CONTINUE 1

int Try(int idx, int sum) {
  int ok = 1;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < idx; ++j) 
      if (combos[i][j]) sum += try[j];
    if (sum > scores[i]) {
      ok = 0;
      break;
    }
  }
  if (ok == 0) return CONTINUE;

  if (idx >= m) {
#ifdef DEBUG
    for (int i = 0; i < m; ++i)
      printf("%d ", try[i]);
    printf("\n");
#endif
    
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < m; ++j) 
        if (combos[i][j]) sum += try[j];
      if (sum != scores[i]) {
        ok = 0;
        break;
      }
    }

    if (ok) {
      for (int i = 0; i < m; ++i) {
        if (query[i]) {
          if (success[i] == -1 || success[i] == try[i]) success[i] = try[i];
          else return NOT_SURE;
        }
      } 
    }

    return CONTINUE;
  }

  // int to = 100 * m - sum;
  int to = 100 - sum;
  for (int score = 0; score <= to; ++score) {
    try[idx] = score;
    int ret = Try(idx + 1, sum + score);
    if (ret != CONTINUE) return ret;
  }
  return CONTINUE;  
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(success, -1, sizeof(success));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) scanf("%d", &combos[i][j]);
      scanf("%d", &scores[i]);
    }
    for (int j = 0; j < m; ++j) scanf("%d", &query[j]);

    switch (Try(0, 0)) {
      case CONTINUE: {
        int ok = 1;
        int sum = 0;
        for (int i = 0; i < m; ++i) {
          if (query[i]) {
            if (success[i] == -1) {
              ok = 0;
              break;
            }
            sum += success[i];
          } 
        }
        if (ok) printf("%d\n", sum);
        else printf("contradictory\n");
      }
        break;
      case NOT_SURE:
        printf("not sure\n");
        break;
    }
  }
}

