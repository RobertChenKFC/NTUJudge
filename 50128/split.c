#include "split.h"
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
int **prev[100000] = {0};
 
void split(int A[], int *a[], int *head[], int k) {
  int n = 0;
  while (a[n++] != NULL);
  memset(head, 0, sizeof(int*) * k);
  memset(a, 0, sizeof(int*) * n);
 
#ifdef DEBUG
  printf("%d elements\n", n);
#endif
 
  for (int i = 0; i < n; ++i) {
    int r = A[i] % k;
    if (prev[r] == NULL) head[r] = &A[i]; 
    else *prev[r] = &A[i];
 
#ifdef DEBUG
    if (prev[r] == NULL) printf("Current: %d, prev: NULL\n", A[i]);
    else printf("Current: %d, prev: %d\n", A[i], **prev[r]);
#endif
 
    prev[r] = &a[i];
  } 
}
