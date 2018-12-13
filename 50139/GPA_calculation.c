#include "GPA_calculation.h"

#include <stdio.h>
#include <stdlib.h>

double ToGPA(char *score) {
  switch (score[0]) {
    case 'A':
      switch (score[1]) {
        case '+': return 4.3;
        case '-': return 3.7;
        default: return 4.0;
      }
    case 'B':
      switch (score[1]) {
        case '+': return 3.3;
        case '-': return 2.7;
        default: return 3.0;
      }
    case 'C':
      switch (score[1]) {
        case '+': return 2.3;
        case '-': return 1.7;
        default: return 2.0;
      }
    case 'F': return 0;
  }
  return -1;
}

int Cmp(const void *pa, const void *pb) {
  struct Student *a = (struct Student*)pa;
  struct Student *b = (struct Student*)pb;
  if (a->GPA > b->GPA) return -1;
  if (a->GPA < b->GPA) return 1;
  return 0;
}

void GPA_calculation(struct Student all_student[], int N) {
  for (int i = 0; i < N; ++i) {
    struct Student *student = &all_student[i];
    student->GPA = 0;
    for (int j = 0; j < student->N_class; ++j) {
      struct Class *class = &student->all_class[j];
      student->GPA += class->academic_credit * ToGPA(class->score);
      student->N_credit += class->academic_credit;
    }
    student->GPA /= student->N_credit;
  }

  qsort(all_student, N, sizeof(struct Student), Cmp);

  int numAwards = (N - 1) / 20 + 1;
  for (int i = 0; i < numAwards; ++i) {
    struct Student *student = &all_student[i];
    if (student->N_credit >= 15 && student->GPA >= 3.38)
      printf("%d %s %f\n", i + 1, student->name, student->GPA);
  }
}

