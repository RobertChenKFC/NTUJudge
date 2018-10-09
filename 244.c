#include <stdio.h>
#include <stdint.h>

int main() {
  int specialPrize = 2000000;
  int prizes[] = {200000, 40000, 10000, 4000, 1000, 200};

  uint64_t specials[3];
  uint64_t firsts[3];
  for (int i = 0; i < 3; ++i)
    scanf("%lu", &specials[i]);
  for (int i = 0; i < 3; ++i)
    scanf("%lu", &firsts[i]);

  uint64_t num;
  uint64_t sum = 0;
  while (scanf("%lu", &num) != EOF) {
    for (int i = 0; i < 3; ++i) {
      if (num == specials[i]) {
        sum += specialPrize;
        break;
      }
      int first = firsts[i];
      int copy = num;
      for (int j = 0; j < 6; ++j) {
        if (first == copy) {
          sum += prizes[j];
          break;
        }
        first = (first * 10) % 100000000;
        copy = (copy * 10) % 100000000;
      }   
    } 
  }

  printf("%lu\n", sum);
}

