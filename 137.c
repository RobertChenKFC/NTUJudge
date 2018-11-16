#include <stdio.h>

int grades[1000000];
int main() {
  int grade;
  int idx = 0;
  while (scanf("%d", &grade) != EOF)
    grades[idx++] = grade;

#ifdef HUNDRED
  int sum = 0;
  for (int i = 0; i < idx; ++i) {
    sum += grades[i]; 
    printf("%d ", grades[i]);
  }
  printf("%.1f\n", (float)sum / idx);

#endif

#ifdef APLUS
  float rankGrade = 0;
  int sum = 0;
  for (int i = 0; i < idx; ++i) {
    int grade = grades[i];
    if (grade >= 90 && grade <= 100) {
      printf("A+ ");
      rankGrade += 4.3;
      sum += 95;
    } else if (grade >= 85 && grade <= 89) {
      printf("A ");
      rankGrade += 4.0;
      sum += 87;
    } else if (grade >= 80 && grade <= 84) {
      printf("A- ");
      rankGrade += 3.7;
      sum += 82;
    } else if (grade >= 77 && grade <= 79) {
      printf("B+ ");
      rankGrade += 3.3;
      sum += 78;
    } else if (grade >= 73 && grade <= 76) {
      printf("B ");
      rankGrade += 3.0;
      sum += 75;
    } else if (grade >= 70 && grade <= 72) {
      printf("B- ");
      rankGrade += 2.7;
      sum += 70;
    } else if (grade >= 67 && grade <= 69) {
      printf("C+ ");
      rankGrade += 2.3;
      sum += 68;
    } else if (grade >= 63 && grade <= 66) {
      printf("C ");
      rankGrade += 2.0;
      sum += 65;
    } else if (grade >= 60 && grade <= 62) {
      printf("C- ");
      rankGrade += 1.7;
      sum += 60;
    } else {
      printf("F ");
      rankGrade += 0;
      sum += 50;
    }
  }
  printf("%.1f %.1f\n", rankGrade / idx, (float)sum / idx);
#endif
}

