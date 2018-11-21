#include <stdio.h>
#include <string.h>

void Swap(char *a, char *b) {
  char t = *a;
  *a = *b;
  *b = t;
}

void Flip(char *s) {
  Swap(s, s + 7);
  Swap(s + 1, s + 6);
  Swap(s + 2, s + 5);
  Swap(s + 3, s + 4);
}

int main() {
  int type;
  scanf("%d", &type);
  char buf[100005] = {0}; 
  char *s = buf;
  if (type == 0) {
    scanf("%s", s);
    int cur = 0, len = strlen(s);
    while (cur <= len) {
      Flip(s);
      printf("%llu\n", *((unsigned long long*)s));
      s += 8;
      cur += 8;
    }
  } else if (type == 1) {
    int n;
    scanf("%d", &n);
    while (n--) {
      scanf("%llu", (unsigned long long*)s);
      Flip(s);
      s += 8;
    }
    printf("%s\n", buf);
  }
}

