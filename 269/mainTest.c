#include "memory.h"

#include <stdio.h>

int main() {
  Memory mem[1000];
  char op;
  while (scanf(" %c", &op) != EOF) {
    int idx;
    int start, len;
    scanf("%d", &idx);
    switch (op) {
      case 'I':
        scanf("%d", &len);
#ifdef DEBUG
        printf("initialize mem[%d] with length %d\n", idx, len);
#endif
        initMemory(&mem[idx], len);
        break;
      case 'A':
        scanf("%d%d", &start, &len);
#ifdef DEBUG
        printf("allocate mem[%d] starting at %d with length %d\n", idx, start, len);
#endif
        allocateMemory(&mem[idx], start, len);
        break;
      case 'P':
#ifdef DEBUG
        printf("print mem[%d]\n", idx);
#endif
        printMemory(&mem[idx]);
        break;
      case 'F':
        scanf("%d%d", &start, &len);
#ifdef DEBUG
        printf("free mem[%d] starting at %d with length %d\n", idx, start, len);
#endif
        freeMemory(&mem[idx], start, len);
        break;
    } 
  }
}

