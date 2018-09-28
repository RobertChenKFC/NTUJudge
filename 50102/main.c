#include <stdint.h>
#include <stdio.h>

int main() {
  char inName1[32], inName2[32], outName[32];
  scanf("%s%s%s", inName1, inName2, outName);

  FILE *in1 = fopen(inName1, "rb");
  FILE *in2 = fopen(inName2, "rb");
  FILE *out = fopen(outName, "wb");
  fseek(in1, 0, SEEK_END);
  fseek(in2, 0, SEEK_END);
  int size1 = ftell(in1);
  int size2 = ftell(in2);

  uint8_t carry = 0;
  uint8_t buf1[4096], buf2[4096];
  int minSize, maxSize;
  FILE *maxFile;
  if (size1 <= size2) {
    minSize = size1;
    maxSize = size2;
    maxFile = in2;
  } else {
    minSize = size2;
    maxSize = size1;
    maxFile = in1;
  }
  fseek(out, maxSize, SEEK_SET);
  int i;
  int chunks = minSize / sizeof(buf1);
  for (i = 0; i < chunks; ++i) {
    fseek(in1, -sizeof(buf1), SEEK_CUR);
    fseek(in2, -sizeof(buf1), SEEK_CUR);
    fseek(out, -sizeof(buf1), SEEK_CUR);
    fread(buf1, 1, sizeof(buf1), in1);
    fread(buf2, 1, sizeof(buf1), in2);

    for (int j = 4095; j >= 0; --j) {
      uint16_t result = (uint16_t)buf1[j] + buf2[j] + carry;
      uint8_t output = result;
      carry = result > UINT8_MAX;
      buf1[j] = output;
    }
    fwrite(buf1, 1, sizeof(buf1), out);

    fseek(in1, -sizeof(buf1), SEEK_CUR);    
    fseek(in2, -sizeof(buf1), SEEK_CUR);    
    fseek(out, -sizeof(buf1), SEEK_CUR);
  }
  i *= sizeof(buf1);
  uint8_t shortbuf1, shortbuf2;
  for (; i < minSize; ++i) {
    fseek(in1, -1, SEEK_CUR);
    fseek(in2, -1, SEEK_CUR);
    fseek(out, -1, SEEK_CUR);
    fread(&shortbuf1, 1, 1, in1);
    fread(&shortbuf2, 1, 1, in2);

    uint16_t result = (uint16_t)shortbuf1 + shortbuf2 + carry;
    uint8_t output = result;
    carry = result > UINT8_MAX;
    fwrite(&output, 1, 1, out);

    fseek(in1, -1, SEEK_CUR);
    fseek(in2, -1, SEEK_CUR);
    fseek(out, -1, SEEK_CUR);
  }
  
  int left = maxSize - i;
  chunks = left / sizeof(buf1);
  for (i = 0; i < chunks; ++i) {
    fseek(maxFile, -sizeof(buf1), SEEK_CUR);
    fseek(out, -sizeof(buf1), SEEK_CUR);
    fread(buf1, 1, sizeof(buf1), maxFile);

    for (int j = 4095; j >= 0; --j) {
      uint16_t result = (uint16_t)buf1[j] + carry;
      uint8_t output = result;
      carry = result > UINT8_MAX;
      buf1[j] = output;
    }

    fwrite(buf1, 1, sizeof(buf1), out);
    fseek(maxFile, -sizeof(buf1), SEEK_CUR);
    fseek(out, -sizeof(buf1), SEEK_CUR);
  }
  int remains = left % sizeof(buf1);
  for (i = 0; i < remains; ++i) {
    fseek(maxFile, -1, SEEK_CUR); 
    fseek(out, -1, SEEK_CUR); 
    fread(&shortbuf1, 1, 1, maxFile);

    uint16_t result = (uint16_t)shortbuf1 + carry;
    shortbuf1 = result;
    carry = result > UINT8_MAX;

    fwrite(&shortbuf1, 1, 1, out);
    fseek(maxFile, -1, SEEK_CUR); 
    fseek(out, -1, SEEK_CUR); 
  }

  fclose(in1);
  fclose(in2);
  fclose(out);
}
