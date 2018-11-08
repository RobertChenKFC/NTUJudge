#include <stdio.h>
#include <string.h>

const char *SUBORDINATE = "subordinate\n";
const char *SUPERVISOR = "supervisor\n";
const char *COLLEAGUE = "colleague\n";
const char *UNRELATED = "unrelated\n";

void GetName (char *s) {
  scanf("%s", s);
  int len = strlen(s);
  s[len] = ' ';
  scanf("%s", s + len + 1);
}

typedef struct Employee {
  int id;
  char name[75];
  int bossid;
  struct Employee *boss;
} Employee;

int FindEmployeeWithID(Employee *employees, int n, int id) {
  for (int i = 0; i < n; ++i)
    if (employees[i].id == id) return i;
}

int FindEmployeeWithName(Employee *employees, int n, char *name) {
  for (int i = 0; i < n; ++i)
    if (strcmp(employees[i].name, name) == 0) return i;
}

int GetAllBosses(Employee *employees, Employee **bosses) {
  Employee *root = employees->boss;
  int nBosses = 0;
  while (root != NULL) {
    bosses[nBosses++] = root;
    root = root->boss;
  }
  return nBosses;
}

int main() {
  Employee employees[35];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    Employee *employee = &employees[i];
    scanf("%d", &employee->id);
    GetName(employee->name);
    scanf("%d", &employee->bossid);
  }

#ifdef DEBUG
  printf("Employees:\n");
  for (int i = 0; i < n; ++i)
    printf("%s\n", employees[i].name);
#endif

  for (int i = 0; i < n; ++i) {
    int j = FindEmployeeWithID(employees, n, employees[i].bossid);
    employees[i].boss = (i == j) ? NULL : &employees[j];
  }
  Employee *bosses[35][35];
  int nBosses[35];
  for (int i = 0; i < n; ++i)
    nBosses[i] = GetAllBosses(&employees[i], bosses[i]);

  const char *relation[35][35];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Employee *a = &employees[i];
      Employee *b = &employees[j];
      for (int k = 0; k < nBosses[i]; ++k) {
        Employee *aBoss = bosses[i][k];
        if (aBoss == b) {
          relation[i][j] = SUBORDINATE; 
          relation[j][i] = SUPERVISOR;
          goto NEXT_PAIR;
        }
      }  
      for (int k = 0; k < nBosses[j]; ++k) {
        Employee *bBoss = bosses[j][k]; 
        if (bBoss == a) {
          relation[j][i] = SUBORDINATE;
          relation[i][j] = SUPERVISOR;
          goto NEXT_PAIR;
        }
      }
      for (int k = 0; k < nBosses[i]; ++k) {
        for (int l = 0; l < nBosses[j]; ++l) {
          if (bosses[i][k] == bosses[j][l]) {
            relation[i][j] = relation[j][i] = COLLEAGUE; 
            goto NEXT_PAIR;
          } 
        } 
      }
      relation[i][j] = relation[j][i] = UNRELATED;
NEXT_PAIR:
      continue;
    } 
  }

  int m;
  scanf("%d", &m);
  while (m--) {
    char name1[75], name2[75];
    GetName(name1);
    GetName(name2);
    int i = FindEmployeeWithName(employees, n, name1);
    int j = FindEmployeeWithName(employees, n, name2);
    printf("%s", relation[i][j]);
  } 
}

