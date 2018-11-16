#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
  int year;
  int month;
  int day;
  char category[35];
  int amount;
  struct Expense *left, *right;
} Expense;

int Cmp(int year1, int month1, int day1, char *category1,
        int year2, int month2, int day2, char *category2) {
  if (year1 == year2) {
    if (month1 == month2) {
      if (day1 == day2)
        return strcmp(category1, category2); 
      return day1 - day2;
    } 
    return month1 - month2;
  }
  return year1 - year2;
}

Expense* Insert(Expense *root, int year, int month, int day, char *category, int amount) {
  if (root == NULL) {
    root = malloc(sizeof(Expense));
    root->year = year;
    root->month = month;
    root->day = day;
    strcpy(root->category, category);
    root->amount = amount;
    root->left = root->right = NULL;
    return root;
  }
  int cmp = Cmp(year, month, day, category,
                root->year, root->month, root->day, root->category);
  if (cmp < 0) root->left = Insert(root->left, year, month, day, category, amount);
  else if (cmp > 0) root->right = Insert(root->right, year, month, day, category, amount); 
  else root->amount += amount; 
  return root;
}

void PrintExpenses(Expense *root) {
  if (root == NULL) return;
  PrintExpenses(root->left);
  printf("%d %d %d %s %d\n", root->year, root->month, root->day, root->category, root->amount);
  PrintExpenses(root->right);
}

int main() {
  int year, month, day, amount;
  char category[35];
  Expense *root = NULL;
  while (scanf("%d", &year) != EOF) {
    scanf("%d%d%s%d", &month, &day, category, &amount); 
    root = Insert(root, year, month, day, category, amount);
  }
  PrintExpenses(root);
}

