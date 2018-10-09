#include <stdio.h>

int main() {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int year, month, day0;
  scanf("%d%d%d", &year, &month, &day0);

  if (month < 1 || month > 12 || day0 < 0 || day0 > 6) {
    printf("invalid\n"); 
    return 0;
  }

  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    days[2] = 29;

  printf(" Su Mo Tu We Th Fr Sa\n");
  printf("=====================\n");
  for (int i = 0; i < day0; ++i)
    printf("   ");
  int currentDay = day0;
  for (int day = 1; day <= days[month]; ++day) {
    printf("%3d", day);
    if (++currentDay == 7) {
      currentDay = 0;
      if (day != days[month])
        printf("\n");
    }
  }
  printf("\n=====================\n");
}

