#include <stdio.h>
#include <string.h>

char words[300][300];
int lens[300];

int main() {
  int m;
  scanf("%d", &m);
  int curWord = 0, curMinLen = 0;
  int len;
  while (scanf("%s", words[curWord]) != EOF) {
    len = strlen(words[curWord]);
    lens[curWord++] = len;
    curMinLen += len;
    if (curMinLen + curWord - 1 > m) {
      curMinLen -= len;
      --curWord;

#ifdef DEBUG
      printf("--Should print to %s\n", words[curWord - 1]);
      printf("--Currently has %d characters, %d left for spaces for %d words\n", curMinLen, m - curMinLen, curWord);
#endif

      int spacing = (curWord == 1) ? 0 : ((m - curMinLen) / (curWord - 1));
      int moreSpacing = (curWord == 1) ? 0 : ((m - curMinLen) % (curWord - 1));
      for (int i = 0; i < curWord; ++i) {
        if (i != 0) {
          if (i <= moreSpacing) for (int j = 0; j < spacing + 1; ++j) printf(" "); 
          else for (int j = 0; j < spacing; ++j) printf(" ");
        }
        printf("%s", words[i]);
      }
      if (curWord == 1) for (int i = m - curMinLen; i > 0; --i) printf(" ");
      printf("\n");
      if (curWord != 0) {
        strcpy(words[0], words[curWord]);
        lens[0] = lens[curWord];
        curWord = 1;
        curMinLen = len;
      }
    }
  }

#ifdef DEBUG
  printf("--Last line with %d characters, %d left for spaces for %d words\n", curMinLen, m - curMinLen, curWord);
#endif


  int spacing = (curWord == 1) ? 0 : ((m - curMinLen) / (curWord - 1));
  int moreSpacing = (curWord == 1) ? 0 : ((m - curMinLen) % (curWord - 1));
  for (int i = 0; i < curWord; ++i) {
    if (i != 0) {
      if (i <= moreSpacing) for (int j = 0; j < spacing + 1; ++j) printf(" "); 
      else for (int j = 0; j < spacing; ++j) printf(" ");
    }
    printf("%s", words[i]);
  }
  if (curWord == 1) for (int i = m - curMinLen; i > 0; --i) printf(" ");
  printf("\n");
}

