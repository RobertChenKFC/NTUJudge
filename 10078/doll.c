#include "doll.h"

#include <stdio.h>
#include <stdlib.h>
 
Doll *newDoll(char top, char bottom) {
  Doll *doll = malloc(sizeof(Doll));
  doll->top = top, doll->bottom = bottom;
  doll->interior = NULL;
  return doll;
}

void package(Doll *outer, Doll *inter) {
  outer->interior = inter;
}

int idx;
char buf[1000000];
void BuildString(Doll *doll) {
  if (doll == NULL) return;
  buf[idx++] = doll->top;
  BuildString(doll->interior);
  buf[idx++] = doll->bottom;
}

const char* doll_c_str(Doll *doll) {
  idx = 0;
  BuildString(doll);
  buf[idx] = '\0';
  return buf;
}
 
