#include <stdio.h>
#include <string.h>

int main() {
  char s[100];
  char last = '\0';
  int sum = 0, maxSum = 0;
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    if (s[0] != last) {
      if (sum > maxSum) maxSum = sum;
      sum = len;
    } else {
      sum += len; 
    }
    last = s[len - 1];
  }
  if (sum > maxSum) maxSum = sum;
  printf("%d\n", maxSum);
}

