#include <stdio.h>
 
int main() {
  unsigned char key;
  scanf("%hhu", &key);
  FILE *in = fopen("test", "rb");
  FILE *out = fopen("test.enc", "wb");
  unsigned char byte;

  while (fread(&byte, sizeof(byte), 1, in)) {
    byte ^= key;
    fwrite(&byte, sizeof(byte), 1, out);
  }
 
  fclose(in);
  fclose(out);
}
