#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char chars[15];
char table[255];
int nChars;

char s1[15], s2[15], s3[15];
int l1, l2, l3;

void AddChars(char *s, int len) {
  for (int i = 0; i < len; ++i) {
    char c = s[i];
    if (!(c >= 'A' && c <= 'Z')) continue;
    int valid = 1;
    for (int j = 0; j < nChars; ++j) {
      if (c == chars[j]) {
        valid = 0;
        break;
      } 
    }
    if (valid) chars[nChars++] = c;
  }
}

void Convert(char *d, char *s, int len) {
  for (int i = 0; i < len; ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') d[i] = table[s[i]];
    else d[i] = s[i];
  }
  d[len] = '\0';
}

int Length(int n) {
  int len = 0;
  while (n) {
    n /= 10;
    ++len;
  }
  return len;
}

int Check(int idx) {
  if (idx == nChars) {
#ifdef DEBUG
    printf("Trying this: \n");
    for (int i = 0; i < nChars; ++i)
      printf("%c -> %c\n", chars[i], table[chars[i]]); 
#endif

    char c1[15], c2[15], c3[15];
    Convert(c1, s1, l1);
    Convert(c2, s2, l2);
    Convert(c3, s3, l3); 
    int n1 = atoi(c1), n2 = atoi(c2), n3 = atoi(c3);
    if (n1 * n2 == n3) {
      printf("%s x %s = %s\n", c1, c2, c3); 
      return 1;
    }
    return 0;
  }
  for (char i = '1'; i <= '9'; ++i) {
    table[chars[idx]] = i;
    if (Check(idx + 1)) return 1;
  }
  return 0;
}

int main() {
  scanf("%s%s%s", s1, s2, s3);

  l1 = strlen(s1);
  l2 = strlen(s2);
  l3 = strlen(s3);
  AddChars(s1, l1);
  AddChars(s2, l2);
  AddChars(s3, l3);

#ifdef DEBUG
  printf("All chars (total of %d):", nChars);
  for (int i = 0; i < nChars; ++i)
    printf(" %c", chars[i]);
  printf("\n");
#endif

  Check(0); 
}

