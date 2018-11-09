#include <stdio.h>
#include <limits.h>

int main() {
  char fileName[205];
  scanf("%s", fileName);
  FILE *in = fopen(fileName, "rb");

  int n;
  fread(&n, sizeof(n), 1, in);
  int count[65536] = {0};
  short number;
  while (n--) {
    fread(&number, sizeof(number), 1, in);
    ++count[(int)number + 32768];
  }
  fclose(in);

  int max = INT_MIN; 
  int maxi;
  for (int i = 0; i < 65536; ++i) {
    if (count[i] >= max) {
      max = count[i];
      maxi = i;
    }
  }
  printf("%d\n%d\n", maxi - 32768, max);
}

