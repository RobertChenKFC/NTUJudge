#include <stdio.h>

int main() {
  int n = 0;
  unsigned long long bookshelf = 0;

  unsigned long long book;
  while (scanf("%llu", &book) != EOF) {
    unsigned long long books = bookshelf;
    unsigned long long mask = 0;
    int found = 0;
    for (int i = 0; i < n; ++i) {
      unsigned long long curBook = books & 0xFFULL;
      mask = (mask << 8) | 0xFFULL;
      if (curBook == book) {
        int shift = i << 3;
        unsigned long long left = bookshelf & (~mask);
        unsigned long long right = bookshelf & mask & (~(0xFFULL << shift));

#ifdef DEBUG
        printf("Left:    %016llx\n (%016llx)\n", left, ~mask);
        printf("Right:   %016llx\n (%016llx)", right, mask & (~(0xFFULL << shift)));
        printf("Book:    %016llx\n (%016llx)", book << shift, 0xFFULL << shift);
#endif

        bookshelf = left | (right << 8) | book;

#ifdef DEBUG
        printf("Merged:  %016llx\n\n", bookshelf);
#endif
        found = 1;
        break;
      }
      books >>= 8;
    }
    if (!found) {
      bookshelf = (bookshelf << 8) | book;
      if (n != 8) ++n;
    }

#ifdef DEBUG
    printf("Current: %016llx\n", bookshelf);
#endif
  }

  int books[8];
  for (int i = 0; i < 8; ++i) {
    books[i] = bookshelf & 0xFFULL;
    bookshelf >>= 8;
  }
  for (int i = 7; i >= 0; --i) {
    if (i != 7) printf(" ");
    printf("%d", books[i]);
  }
  printf("\n");
}

