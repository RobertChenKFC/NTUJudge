#include <stdio.h>

int Min(int a, int b) {
  if (b < 0) return a;
  return a <= b ? a : b;
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int D, a, b, c, A, B, C;
    scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
    int I = (A == 0) ? a : Min(a, (D / A) + 1);
    for (int i = 0; i <= I; ++i) {
      int J = (B == 0) ? b : Min(b, (D - A * i) / B + 1);
      for (int j = 0; j <= J; ++j) {
        int K = (C == 0) ? c : Min(c, (D - A * i - B * j) / C + 1);
        for (int k = 0; k <= K; ++k) {
          if (A * i + B * j + C * k == D) {
            printf("yes\n"); 
            goto NEXT;
          }
        } 
      } 
    }
    printf("no\n");
NEXT:
    continue;
  }
}

