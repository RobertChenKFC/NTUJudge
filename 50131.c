#include <stdio.h>
#include <string.h>

#define IS_VOWEL(X) ((X) == 'a' || (X) == 'e' || (X) == 'i' || (X) == 'o' || (X) == 'u')

int main() {
  char str[10005];
  int idx[10005];
  while (scanf("%s", str) != EOF) {
    int len = strlen(str);
    int first, second;
    scanf("%d%d", &first, &second);
    int numSyllables = 0;
    for (int i = 0; i < len; ++i) {
      idx[i] = numSyllables;
      if (IS_VOWEL(str[i])) ++numSyllables;
    }

#ifdef DEBUG
    printf("Syllable indicies:\n");
    for (int i = 0; i < len; ++i)
      printf("%d ", idx[i]);
    printf("\n");
#endif

    for (int i = 0; i < len; ++i) {
      if (idx[i] == first) {
        printf("%c", str[i]); 
        idx[i] = -1;
      } else {
        printf("+"); 
      }
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
      if (idx[i] == second) {
        printf("%c", str[i]); 
        idx[i] = -1;
      } else {
        printf("+"); 
      }
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
      if (idx[i] != -1) printf("%c", str[i]); 
      else printf("+"); 
    }
    printf("\n");

  }
}

