#include <stdio.h>

#include "value.h"

int main() {
  printf("%d\n%d\n%d\n", value(79, 4, 8, 2), value(100, -4, 8, 2), value(79, 0, 8, 2));
}

