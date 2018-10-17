#include <stdio.h>
#include <string.h>

char segments[10][7] = {
  {1, 1, 1, 0, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0},
  {1, 0, 1, 1, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {0, 1, 1, 1, 0, 1, 0},
  {1, 1, 0, 1, 0, 1, 1},
  {1, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 0}
};

void PrintSegment(char buf[15][101], char digit, int i0, int j0, int width, int height) {
#ifdef DEBUG
  printf("(i0, j0, width, height) = (%d, %d, %d, %d)\n", i0, j0, width, height);
#endif

  int idx = digit - '0';
  int segWidth = width - 3, segHeight = (height - 3) / 2;
  if (segments[idx][0]) for (int i = 0; i < segWidth; ++i) buf[i0][j0 + 1 + i] = digit;
  if (segments[idx][1]) for (int i = 0; i < segHeight; ++i) buf[i0 + 1 + i][j0] = digit;
  if (segments[idx][2]) for (int i = 0; i < segHeight; ++i) buf[i0 + 1 + i][j0 + 1 + segWidth] = digit;
  if (segments[idx][3]) for (int i = 0; i < segWidth; ++i) buf[i0 + 1 + segHeight][j0 + 1 + i] = digit;
  if (segments[idx][4]) for (int i = 0; i < segHeight; ++i) buf[i0 + 2 + i + segHeight][j0] = digit;
  if (segments[idx][5]) for (int i = 0; i < segHeight; ++i) buf[i0 + 2 + i + segHeight][j0 + 1 + segWidth] = digit;
  if (segments[idx][6]) for (int i = 0; i < segWidth; ++i) buf[i0 + 2 * (segHeight + 1)][j0 + 1 + i] = digit;
}

int main() {
  char buf[15][101];
  char s[11];
  while (scanf("%s", s) != EOF) {
    int width, height;
    scanf("%d%d", &width, &height);
    int len = strlen(s);

#ifdef DEBUG
    printf("width: %d, height: %d\n", width, height);
#endif

    int totalWidth = width * len;
    int mod = (height - 3) / 2 + 1;
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < totalWidth; ++j)
        buf[i][j] = (j == totalWidth - 1) ? '\0' : ' ';
    }
    
    int i0 = 0, j0 = 0;
    for (int i = 0; i < len; ++i) {
      PrintSegment(buf, s[i], i0, j0, width, height);
      j0 += width;

#ifdef DEBUG
      printf("j0 of %d is %d\n", i0, j0);
#endif
    }

    for (int i = 0; i < height; ++i) {
      int j;
      for (j = totalWidth - 2; j >= 0; --j) {
        if (buf[i][j] >= '0' && buf[i][j] <= '9')
          break;
      }
      buf[i][j + 1] = '\0';

      printf("%s\n", buf[i]);
    }
  }
}

