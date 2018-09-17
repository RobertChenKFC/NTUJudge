#include <stdio.h>
#include <string.h>

int main() {
  int table[26][26] = {0};
  int t;
  scanf("%d", &t);
  char s[100];
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    for (int i = 1; i < len; ++i)
      ++table[s[i - 1] - 'a'][s[i] - 'a']; 
  }
  int max = t;
  int maxi, maxj;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (j != 0) printf(" ");
      printf("%d", table[i][j]);
      if (table[i][j] > max) {
        max = table[i][j]; 
        maxi = i, maxj = j;
      }
    }
    printf("\n");
  }
  char str[26] = {0};
  int used['z'] = {0};
  int idx = 0;
  while (!used[maxi]) {
    str[idx++] = maxi + 'a';
    used[maxi] = 1;
    max = t;
    maxj = maxi;
    for (int j = 0; j < 26; ++j) {
      if (!used[j] && table[maxi][j] > max) {
        max = table[maxi][j];
        maxj = j;
      }
    }
    maxi = maxj;
  }
  printf("%s\n", str);
}
