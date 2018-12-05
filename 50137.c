#include <stdio.h>

int n;
int w[205];
int h[205];
int chosen[205] = {0};

typedef struct {
  int num;
  int sum;
} Stack;
Stack minStack = {-1, -1};
Stack emptyStack = {0, 0};

int Greater(Stack a, Stack b) {
  if (a.num == b.num) return a.sum > b.sum; 
  return a.num > b.num;
}

Stack Fit(int idx, int curw, int curh, Stack stack) {
  if (idx >= n) return stack;

  Stack max = stack;
  for (int i = idx; i < n; ++i) {
    if (!chosen[i] && ((curw >= w[i] && curh >= h[i]) ||
                       (curw >= h[i] && curh >= w[i]))) {
      chosen[i] = 1;

      Stack newStack = stack;
      newStack.num += 1;
      newStack.sum += i;

      Stack cur = Fit(i + 1, w[i], h[i], newStack);
      if (Greater(cur, max)) max = cur;

      chosen[i] = 0;
    }
  }
  return max;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &w[i], &h[i]);
  Stack stack = Fit(0, 1005, 1005, emptyStack);
  printf("%d %d\n", stack.num, stack.sum);
}

