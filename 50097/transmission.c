#include "transmission.h"

#include <stdio.h>
#include <string.h>

long long int buf[1048576];

void transmission(long long int belt[], int N, int T) {
  int full = (T / 64) % N;
  for (int i = 0; i < N; ++i) {
    int j = (i >= full) ? (i - full) : (i - full + N);
    buf[j] = belt[i];
  }
  memcpy(belt, buf, N * sizeof(long long int));

  T %= 64;
  long long int carry;
  for (int t = 0; t < T; ++t) {
    carry = 0;
    for (int i = N - 1; i >= 0; --i) {
      long long int oldCarry = carry;
      carry = (belt[i] & (1LL << 63)) ? 1 : 0;
      belt[i] = (belt[i] << 1) | oldCarry;
    }
    if (carry) belt[N - 1] |= carry;
  }
}
