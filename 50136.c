#include <stdio.h>
#include <stdlib.h>
 
char Wrap(int c) {
 
#ifdef DEBUG
  printf("%c(%d)\n", c, (int)(c - 'a'));
#endif
 
  while (c > 'z') c -= 26;
  return c;
}
 
int Cmp(const void *a, const void *b) {
  return (int)(*((char*)a) - *((char*)b));
}
 
void Build(char *s, int idx, char c, int k, int l, unsigned long long n, unsigned long long *cnt) {
  if (*cnt >= n) return;
  if (idx >= l) {
    ++(*cnt);
    s[idx] = '\0';
    printf("%s\n", s);
    return;
  }
  char chars[30];
  for (int i = 1; i <= k; ++i)
    chars[i - 1] = Wrap((int)c + i);
 
#ifdef DEBUG
  printf("Distance of %d to %c:", k, c);
  for (int i = 0; i < k; ++i)
    printf(" %c(%d)", chars[i], (int)(chars[i] - 'a'));
  printf("\n");
#endif
 
  qsort(chars, k, sizeof(char), Cmp);
 
#ifdef DEBUG
  printf("Distance of %d to %c:", k, c);
  for (int i = 0; i < k; ++i)
    printf(" %c", chars[i]);
  printf("\n");
#endif
 
  for (int i = 0; i < k; ++i) {
    s[idx] = chars[i];
    Build(s, idx + 1, chars[i], k, l, n, cnt);
  }
}
 
int main() {
  char c;
  int k, l;
  unsigned long long n;
  scanf("%c%d%d%llu", &c, &k, &l, &n);
  char buf[1030];
  buf[0] = c;
  unsigned long long cnt = 0;
  Build(buf, 1, c, k, l, n, &cnt);
}
