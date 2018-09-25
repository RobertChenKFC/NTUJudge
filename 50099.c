#include <stdio.h>

long long weights[16384];
int pivot[16384] = {0};

void findPivot(int from, int to)  {
  if (to - from < 2) return;
  int chosen = 0;
  int curPivot = -1;
  for (int i = from; i <= to; ++i) {
    long long torque = 0;
    for (int j = from; j <= to; ++j)
      torque += (j - i) * weights[j];
    if (torque == 0) {
      pivot[i] = 1;
      curPivot = i;
      break;
    }
  } 
  if (curPivot != -1) {
    findPivot(from, curPivot - 1);
    findPivot(curPivot + 1, to);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &weights[i]); 
  findPivot(0, n - 1);
  for (int i = 0; i < n; ++i)
    if (pivot[i]) printf("%d\n", i); 
}
