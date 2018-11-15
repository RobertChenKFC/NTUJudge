#include "book.h"
#include "date.h"

#include <time.h>
#include <stdio.h>

struct tm GetTime(struct Date date) {
  struct tm t = {0, 0, 0, date.day, date.month - 1, date.year - 1900};
  return t;
}

unsigned int MAX_DAYS[] = {90, 10, 100, 5};
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
  struct tm start = GetTime(date_borrowed), end = GetTime(date_returned);

#ifdef DEBUG
  char buf1[80], buf2[80];
  strftime(buf1, sizeof(buf1), "%A %c", &start);
  strftime(buf2, sizeof(buf2), "%A %c", &end);
  printf("date borrowed: %s, date returned: %s\n", buf1, buf2);
#endif

  unsigned int days = difftime(mktime(&end), mktime(&start)) / 86400 + 1;

#ifdef DEBUG
  printf("%lf day difference\n", difftime(mktime(&end), mktime(&start)) / 86400 + 1);
#endif

  if (days > MAX_DAYS[book.type]) {
    int dist = -1;
    for (int i = 0; i < 32; ++i) {
      if (book.importance & (1 << i)) {
        if (dist == -1) {
          dist = i;
        } else {
          dist = i - dist - 1; 
          break;
        }
      }
    }
    return dist * (days - MAX_DAYS[book.type]);
  }
  return 0;
}

