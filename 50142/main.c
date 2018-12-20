#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  FILE *in[25], *out;
  char name[25];
  for (int i = 0; i < n; ++i) {
    scanf("%s", name); 
    in[i] = fopen(name, "r");
  }
  scanf("%s", name); 
  out = fopen(name, "w");

  char done[25] = {0};
  while (1) {

#ifdef DEBUG
    printf("New round\n");
#endif

    int ok = 1;
    char min[4] = {0};
    int minIdx = 0;
    for (int i = 0; i < n; ++i) {
      char cur[4] = {0};
      if (!done[i]) {
        int ret = fread(cur, 3, sizeof(char), in[i]); 
        fseek(in[i], -3, SEEK_CUR);

#ifdef DEBUG
        if (ret != 0)
          printf("%s\n", cur);
#endif

        if (ret == 0) done[i] = 1;
        else {
          ok = 0;
          if (min[0] == '\0' || strcmp(min, cur) > 0) {
            strcpy(min, cur);
            minIdx = i;
          }
        }
      }
    }    
    if (!ok) {
#ifdef DEBUG
      printf("Writing %s\n", min);
#endif

      fwrite(min, 3, sizeof(char), out);
      fseek(in[minIdx], 3, SEEK_CUR);
    } else break;
  }

  for (int i = 0; i < n; ++i) fclose(in[i]);
  fclose(out);
}

