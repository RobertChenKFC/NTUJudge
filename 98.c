#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char name[65];
  char ingredients[10][65];
  int numIngredients;
} Food;
Food foods[100];

int Cmp(const void *a, const void *b) {
  return strcmp(*((char **)a), *((char **)b));
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", foods[i].name, &foods[i].numIngredients);
    for (int j = 0; j < foods[i].numIngredients; ++j)
      scanf("%s", foods[i].ingredients[j]);
  }

  int m;
  scanf("%d", &m);
  while (m--) {
    char name1[65], name2[65];
    char *common[10];
    int numCommon = 0;

    scanf("%s%s", name1, name2);
    int i = -1, j = -1;
    for (int k = 0; k < n && (i == -1 || j == -1); ++k) {
      if (i == -1 && strcmp(foods[k].name, name1) == 0) i = k;
      if (j == -1 && strcmp(foods[k].name, name2) == 0) j = k;
    }

#ifdef DEBUG
    printf("\nIngredients: %s(%d) %s(%d)\n", name1, foods[i].numIngredients,
                                             name2, foods[j].numIngredients);
#endif

    for (int k = 0; k < foods[i].numIngredients; ++k) {
      for (int l = 0; l < foods[j].numIngredients; ++l) {
#ifdef DEBUG
        printf("%s %s\n", foods[i].ingredients[k], foods[j].ingredients[k]); 
#endif
        if (strcmp(foods[i].ingredients[k], foods[j].ingredients[l]) == 0) {
          common[numCommon++] = foods[i].ingredients[k];
          break;
        }
      }
    }
    if (numCommon != 0) {
      qsort(common, numCommon, sizeof(char *), Cmp);
      for (int i = 0; i < numCommon; ++i) {
        if (i != 0) printf(" ");
        printf("%s", common[i]);
      }
      printf("\n");
    } else {
      printf("nothing\n");
    }
  }
}

