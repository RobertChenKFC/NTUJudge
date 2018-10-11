#include "card.h"

#include <stdio.h>

int *buf[10000];
void shuffle(int *deck[]) {
  int n = 0;
  int **ptr = deck;
  while (*ptr != NULL) {
    ++ptr;
    ++n;
  }

  int mid = (n & 1) ? (n / 2 + 1) : (n / 2);
  int first = 1;
  for (int i = 0, j = mid, idx = 0; idx < n; ++idx) {
    if (first)
      buf[idx] = deck[i++];
    else
      buf[idx] = deck[j++];
    first = !first;
  }

  for (int i = 0; i < n; ++i)
    deck[i] = buf[i]; 
  deck[n] = NULL;
}

void print(int *deck[]) {
  int **ptr = deck, **initial = deck;
  while (*ptr != NULL) {
    if (ptr != initial) printf(" ");
    printf("%d", **ptr);
    ++ptr;
  }
}

