#include <stdio.h> 
#include <stdlib.h>

void merge(int A[], int B[], int* a[], int* b[]) {
  int n = 0, m = 0;
  while (a[n++] != NULL);
  while (b[m++] != NULL);

  int total = n + m;
  int **merged = malloc(sizeof(int*) * total);
  int **last = merged + total;
  int ***posA = malloc(sizeof(int**) * n);
  int ***posB = malloc(sizeof(int**) * m);
  for (int i = 0, j = 0, idx = 0; idx < total; ++idx) {
    if (i >= n) {
      posB[j] = &merged[idx];
      merged[idx] = &B[j++]; 
    }
    else if (j >= m) {
      posA[i] = &merged[idx];
      merged[idx] = &A[i++]; 
    } else if (A[i] < B[j]) {
      posA[i] = &merged[idx];
      merged[idx] = &A[i++]; 
    } else {
      posB[j] = &merged[idx];
      merged[idx] = &B[j++];
    }
  }

#ifdef DEBUG
  for (int i = 0; i < total; ++i)
    printf("%d ", *merged[i]);
  printf("\n");
#endif

  for (int i = 0; i < n; ++i)
    a[i] = (posA[i] + 1 == last) ? NULL : *(posA[i] + 1);
  for (int i = 0; i < m; ++i) {
    b[i] = (posB[i] + 1 == last) ? NULL : *(posB[i] + 1);
  }
}

