#include "memory.h"

#include <stdio.h>
#include <stdlib.h>

void initMemory(Memory *memory, int length) {
  memory->head = malloc(sizeof(FreeBlock));
  memory->head->start = 0;
  memory->head->len = length;
  memory->head->next = NULL;
}

void printMemory(Memory *memory) {
  FreeBlock *cur = memory->head;
  printf("==========\n");
  while (cur != NULL) {
    printf("start %d, length %d\n", cur->start, cur->len);
    cur = cur->next;
  }
}

void allocateMemory(Memory *memory, int start, int length) {
  FreeBlock *cur = memory->head, *prev = NULL;
  if (cur == NULL) return;
  while (cur->next != NULL && !(start >= cur->start && start + length <= cur->start + cur->len)) {
    prev = cur;
    cur = cur->next;
  }
  
  int left = cur->start, right = start + length;
  int leftLen = start - cur->start, rightLen = cur->start + cur->len - start - length;
#ifdef DEBUG
  printf("left block: %d %d, right block: %d %d\n", left, leftLen, right, rightLen);
#endif

  if (prev == NULL) {
#ifdef DEBUG
    printf("allocating the leftmost block\n");
#endif
    if (leftLen == 0 && rightLen == 0) {
      memory->head = cur->next; 
      free(cur);
    } else if (leftLen == 0) {
      memory->head->start = right;
      memory->head->len = rightLen;
    } else if (rightLen == 0) {
      memory->head->start = left;
      memory->head->len = leftLen;
    } else {
      FreeBlock *leftBlock = malloc(sizeof(FreeBlock)), *rightBlock = cur;
      leftBlock->start = left;
      leftBlock->len = leftLen;
      rightBlock->start = right;
      rightBlock->len = rightLen;
      memory->head = leftBlock;
      leftBlock->next = rightBlock;
      rightBlock->next = cur->next;
    }
  } else {
#ifdef DEBUG
    printf("allocating a normal block\n");
#endif
    if (leftLen == 0 && rightLen == 0) {
      prev->next = cur->next;
      free(cur);
    } else if (leftLen == 0) {
      cur->start = right;
      cur->len = rightLen;
    } else if (rightLen == 0) {
      cur->len = leftLen;
    } else {
      FreeBlock *leftBlock = malloc(sizeof(FreeBlock)), *rightBlock = cur; 
      leftBlock->start = left;
      leftBlock->len = leftLen;
      rightBlock->start = right;
      rightBlock->len = rightLen;
      prev->next = leftBlock;
      leftBlock->next = rightBlock;
      rightBlock->next = cur->next;
    }
  }
}

void freeMemory(Memory *memory, int start, int length) {
  FreeBlock *cur = memory->head, *prev = NULL;
  while (cur != NULL &&
         !(prev == NULL && start < cur->start) &&
         !(prev != NULL && (prev->start + prev->len <= start && start < cur->start))) {
    prev = cur;
    cur = cur->next;
  }
  if (prev == NULL && cur == NULL) {
    // no free blocks left
    memory->head = malloc(sizeof(FreeBlock));
    memory->head->start = start;
    memory->head->len = length;
    memory->head->next = NULL;
  } else if (prev == NULL) {
    // block on the left side
    if (start + length == cur->start) {
      cur->start = start;
      cur->len += length;
    } else {
      memory->head = malloc(sizeof(FreeBlock));
      memory->head->start = start;
      memory->head->len = length;
      memory->head->next = cur;
    }
  } else if (cur == NULL) {
    // block on the right side 
    if (prev->start + prev->len == start) {
      prev->len += length; 
    } else {
      prev->next = malloc(sizeof(FreeBlock));
      prev->next->start = start;
      prev->next->len = length;
      prev->next->next = NULL;
    }
  } else {
    if (prev->start + prev->len == start && start + length == cur->start) {
      prev->len += length + cur->len;
      prev->next = cur->next; 
      free(cur);
    } else if (prev->start + prev->len == start) {
      prev->len += length;
      prev->next = cur; // unnecessary?
    } else if (start + length == cur->start) {
      cur->len += length;
      prev->next = cur; // unnecessary?
    } else {
      FreeBlock *mid = malloc(sizeof(FreeBlock));
      mid->start = start;
      mid->len = length;
      prev->next = mid;
      mid->next = cur; 
    }
  }
}

