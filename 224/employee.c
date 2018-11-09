#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}

Employee* find_employee_by_id(Employee *set, int n, int id) {
  for (int i = 0; i < n; ++i)
    if (id == set[i].id) return &set[i]; 
  return NULL;
}

Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name) {
  for (int i = 0; i < n; ++i)
    if (strcmp(first_name, set[i].first_name) == 0 && strcmp(last_name, set[i].last_name) == 0) return &set[i]; 
  return NULL;
}

Employee* find_root_boss(Employee *set, int n, Employee *employee) {
  Employee *prev = employee, *cur = find_employee_by_id(set, n, employee->boss_id);
  while (prev != cur) {
    prev = cur;
    cur = find_employee_by_id(set, n, cur->boss_id);
  }
  return cur;
}

int FindAllBosses(Employee *set, int n, Employee *employee, Employee **bosses) {
  Employee *prev = employee, *cur = find_employee_by_id(set, n, employee->boss_id);
  int nBosses = 0;
  while (prev != cur) {
    bosses[nBosses++] = cur;
    prev = cur;
    cur = find_employee_by_id(set, n, cur->boss_id);
  }
  return nBosses;
}
 
int check_relationship(Employee *set, int n, Employee *A, Employee *B) {
  Employee *bossesA[35];
  int nBossesA = FindAllBosses(set, n, A, bossesA);
  Employee *bossesB[35];
  int nBossesB = FindAllBosses(set, n, B, bossesB);
  for (int i = 0; i < nBossesA; ++i)
    if (bossesA[i] == B) return 1;
  for (int i = 0; i < nBossesB; ++i)
    if (bossesB[i] == A) return 2;
  for (int i = 0; i < nBossesA; ++i) {
    for (int j = 0; j < nBossesB; ++j)
      if (bossesA[i] == bossesB[j]) return 3;
  }
  return 4;
}

void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}
