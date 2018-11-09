#include "employee.h"

int GetAllBosses(Employee *employee, Employee *bosses[35]) {
  Employee *prev = employee;
  Employee *cur = employee->boss;
  int nBosses = 0;
  while (prev != cur) {
    bosses[nBosses++] = cur;
    prev = cur;
    cur = cur->boss;
  }
  return nBosses;
}
 
int relation(Employee *employee1, Employee *employee2) {
  Employee *bosses1[35];
  Employee *bosses2[35];
  int nBosses1 = GetAllBosses(employee1, bosses1);
  int nBosses2 = GetAllBosses(employee2, bosses2);
  for (int i = 0; i < nBosses1; ++i)
    if (bosses1[i] == employee2) return 1;
  for (int i = 0; i < nBosses2; ++i)
    if (bosses2[i] == employee1) return 2;
  for (int i = 0; i < nBosses1; ++i) {
    for (int j = 0; j < nBosses2; ++j)
      if (bosses1[i] == bosses2[j]) return 3;
  }
  return 4;
}
