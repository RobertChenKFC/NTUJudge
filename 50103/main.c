#include <stdio.h>
#include <stdint.h>

// DEBUG
void PrintByte(uint8_t x) {
  for (int i = 0; i < 8; ++i) {
    printf("%c", (x & 128) ? '1' : '0');
    x <<= 1;
  }
}

int main() {
  uint8_t reverse[256];
  for (int i = 0; i < 256; ++i) {
    uint8_t x = i;
    reverse[i] = 0;
    for (int j = 0; j < 8; ++j) {
      reverse[i] = (reverse[i] << 1) | (x & 1); 
      x >>= 1;
    }
  }

  char inName[16], outName[16];
  int shift;
  scanf("%s%s%d", inName, outName, &shift);

  FILE *in = fopen(inName, "rb");
  FILE *out = fopen(outName, "wb");
  fseek(in, 0, SEEK_END);
  int size = ftell(in);
  int pos = (shift == 0) ? shift : (size - shift);
  fseek(out, pos, SEEK_SET);
  for (int i = 0, j = pos; i < size; ++i, ++j) {
    fseek(in, -1, SEEK_CUR);
    if (j == size) {
      j = 0;
      fseek(out, 0, SEEK_SET);
    }
    uint8_t byte;
    fread(&byte, 1, 1, in);
    fwrite(&reverse[byte], 1, 1, out);
    fseek(in, -1, SEEK_CUR);
  }

  fclose(in);
  fclose(out);
}
