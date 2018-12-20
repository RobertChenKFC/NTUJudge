#include "conversion.h"
 
#include <stdio.h>
#include <string.h>
 
void bin2ascii(char input_file[32], char output_file[32], char dict[17]) {
  FILE *in = fopen(input_file, "rb");
  FILE *out = fopen(output_file, "w");
 
  fseek(in, 0, SEEK_END);
  int size = ftell(in);
  fseek(in, 0, SEEK_SET);
 
  for (int i = 0; i < size; ++i) {
    char c;
    fread(&c, sizeof(char), 1, in);
    char buf[2];
    buf[0] = dict[(c >> 4) & 0xF], buf[1] = dict[c & 0xF];
    fwrite(buf, sizeof(char), 2, out);
  }
 
  fclose(in);
  fclose(out);
}
 
void PrintByte(char byte) {
  for (int i = 7; i >= 0; --i)
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  printf("\n");
}
 
void ascii2bin(char input_file[32], char output_file[32], char dict[17]) {
  FILE *in = fopen(input_file, "r");
  FILE *out = fopen(output_file, "wb");
 
  fseek(in, 0, SEEK_END);
  int size = ftell(in);
  fseek(in, 0, SEEK_SET);
 
  const int batchSize = 4096;
  int batches = (size / batchSize) + (size % batchSize != 0);
 
  char str[4096] = {0};
  for (int k = 0; k < batches; ++k) {
    int curSize = (k != batches - 1) ? batchSize : size % batchSize;
    fread(str, sizeof(char), curSize, in);
    for (int i = 0; i < curSize; i += 2) {
      char idx1 = 0;
      while (dict[idx1] != str[i]) ++idx1;
      char idx2 = 0;
      while (i + 1 < size && dict[idx2] != str[i + 1]) ++idx2;
      char byte = (idx1 << 4) | idx2;
      fwrite(&byte, sizeof(char), 1, out);
    }
  }
 
  fclose(in);
  fclose(out);
}
