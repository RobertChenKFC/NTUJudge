#include <stdio.h>

int weights[20];
int values[20];
int n, w;

int Knapsack(int curWeight, int curValue, int cur) {
  if (cur >= n) return curValue;
  int w1 = Knapsack(curWeight, curValue, cur + 1);
  int w2 = 0;
  if (curWeight + weights[cur] <= w)
    w2 = Knapsack(curWeight + weights[cur], curValue + values[cur], cur + 1);
  return w1 >= w2 ? w1 : w2;
}

int main() {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &weights[i], &values[i]);
  printf("%d\n", Knapsack(0, 0, 0));
}

