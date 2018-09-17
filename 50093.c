#include <stdio.h>
#include <string.h>

int main() {
  char str[1024];
  scanf("%s", str);
  char ins[1024];
  char *a, *b;
  char buf[1024];
  while (scanf("%s", ins) != EOF) {
    if (ins[0] == 's') {
      char delim[2] = {0};
      delim[0] = ins[1];
      a = strtok(ins + 2, delim);
      b = strtok(NULL, delim);
      char *pos = strstr(str, a);
      if (pos != NULL) {
        int len = strlen(str);
        int lena = strlen(a), lenb = strlen(b);
        if (lena == lenb) {
          strncpy(pos, b, lena);
        } else if (lena > lenb) {
          strncpy(pos, b, lenb); 
          int remain = len - ((int)(pos - str) + lena);
          strncpy(buf, pos + lena, remain);
          strncpy(pos + lenb, buf, remain);
          *(pos + lenb + remain) = '\0';
        } else {
          int remain = len - ((int)(pos - str) + lena);
          strncpy(buf, pos + lena, remain);
          strncpy(pos, b, lenb);
          strncpy(pos + lenb, buf, remain);
          *(pos + lenb + remain) = '\0';
        }
      }
    } else {
      printf("%s\n", str); 
    }
  } 
}
