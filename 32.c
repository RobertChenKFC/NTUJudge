#include <stdio.h>
#include <limits.h>

int arr[100];
int isPalindrome[100][100] = {0};

int IsPalindrome(int from, int to) {
  for (int i = from, j = to; i < j; ++i, --j)
    if (arr[i] != arr[j]) return 0; 
  return 1;
}

int IsDoublePalindrome(int from, int to) {
  for (int mid = from; mid < to; ++mid) {
    if (isPalindrome[from][mid] && isPalindrome[mid + 1][to])
      return 1;
  }
  return 0;
}

int main() {
  int n = 0;
  int x;
  while (scanf("%d", &x) != EOF)
    arr[n++] = x; 

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (IsPalindrome(i, j))
        isPalindrome[i][j] = 1; 
    }
  }

  int maxLen = INT_MIN;
  int maxi, maxj;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j >= 0; --j) {
      if (i - j > maxLen && IsDoublePalindrome(j, i)) {
        maxLen = i - j;
        maxi = i;
        maxj = j;
      } 
    } 
  }

  for (int i = maxj; i <= maxi; ++i) {
    if (i != maxj) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

