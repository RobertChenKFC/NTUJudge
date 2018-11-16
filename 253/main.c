#include "time.h"

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  Time times[n];
  char operation;
  while (scanf(" %c", &operation) != EOF) {
    int idx, a, b, c;
    scanf("%d", &idx);
    switch (operation) {
      case 'i':
        initTime(&times[idx]);
        break;
      case 's':
        scanf("%d%d%d", &a, &b, &c);
        setTime(&times[idx], a, b, c);
        break;
      case 'a':
        scanf("%d%d%d", &a, &b, &c);
        addTime(&times[idx], a, b, c);
        break;
      case 'p':
        printTime(&times[idx]);
        break;
    } 
  }
}

