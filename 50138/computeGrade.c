#include "computeGrade.h"
 
#include <stdio.h>
 
void computeGrade(Classes classes[2]) {
  for (int i = 0; i < 18; ++i) {
    double sum1 = 0;
    for (int j = 0; j < classes[0].numStudent; ++j)
      sum1 += classes[0].student[j].score[i].rawScore; 
    sum1 /= classes[0].numStudent;
    double sum2 = 0;
    for (int j = 0; j < classes[1].numStudent; ++j)
      sum2 += classes[1].student[j].score[i].rawScore; 
    sum2 /= classes[1].numStudent;
 
 
    if (sum1 >= sum2) {
#ifdef DEBUG
      printf("Class 0\n");
#endif
 
      for (int j = 0; j < classes[0].numStudent; ++j)
          classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
      double r = sum1 / sum2;
 
      for (int j = 0; j < classes[1].numStudent; ++j) {
        classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore * r; 
        if (classes[1].student[j].score[i].scaledScore > 100) 
          classes[1].student[j].score[i].scaledScore = 100;
 
#ifdef DEBUG
        printf("%f ", classes[0].student[j].score[i].scaledScore);
#endif
 
      }
#ifdef DEBUG
      printf("\n");
#endif
 
    } else if (sum1 < sum2) {
#ifdef DEBUG
      printf("Class 1\n");
#endif
      for (int j = 0; j < classes[1].numStudent; ++j)
          classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
      double r = sum2 / sum1;
      for (int j = 0; j < classes[0].numStudent; ++j) {
        classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore * r; 
        if (classes[0].student[j].score[i].scaledScore > 100) 
          classes[0].student[j].score[i].scaledScore = 100;
 
#ifdef DEBUG
        printf("%f ", classes[0].student[j].score[i].scaledScore);
#endif
      }
#ifdef DEBUG
      printf("\n");
#endif
 
    }
  }
 
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < classes[k].numStudent; ++i) {
      double sum = 0;
      for (int j = 0; j < 18; ++j) sum += classes[k].student[i].score[j].scaledScore;
      sum *= 0.06;
      if (sum > 100) sum = 100;
      printf("%s %f\n", classes[k].student[i].id, sum);
    }
  }
}
