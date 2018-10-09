#include <stdio.h>

int main() {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year, day0;
  scanf("%d%d", &year, &day0);

  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    days[2] = 29;

  int n;
  scanf("%d", &n);
  while (n--) {
    int month, date;
    scanf("%d%d", &month, &date);

    if (month < 1 || month > 12) {
      printf("-1\n"); 
    } else if (date < 1 || date > days[month]) {
      printf("-2\n"); 
    } else {
      int day = day0;
      for (int i = 1; i < month; ++i) 
        day += days[i];
      day += date - 1;
      printf("%d\n", day % 7);
    }
  }
}

