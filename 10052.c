#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double Parse(char *s) {
  while (isspace(*s)) ++s;
  if (s[0] == '(') {
    char *pstr = s + 1;
    double p = Parse(pstr);

    char *exp1 = pstr;
    if (*exp1 == '(') {
      ++exp1;
      int cnt = 1;
      while (cnt != 0) {
        if (*exp1 == '(') ++cnt;
        else if (*exp1 == ')') --cnt;
        ++exp1;
      }
      ++exp1;
    } else {
      while (!isspace(*exp1)) ++exp1;
    }
    while (isspace(*exp1)) ++exp1;
    double expr1 = Parse(exp1);

    char *exp2 = exp1;
    if (*exp2 == '(') {
      ++exp2;
      int cnt = 1;
      while (cnt != 0) {
        if (*exp2 == '(') ++cnt;
        else if (*exp2 == ')') --cnt;
        ++exp2;
      }
      ++exp2;
    } else {
      while (!isspace(*exp2)) ++exp2; 
    }
    while (isspace(*exp2)) ++exp2;
    double expr2 = Parse(exp2);

#ifdef DEBUG
    printf("str: %s", s);
    printf("p: %.2lf, expr1: %.2lf, expr2: %.2lf\n\n", p, expr1, expr2);
#endif

    return p * (expr1 + expr2) + (1 - p) * (expr1 - expr2);
  }
  
  char *cur = s;
  while (isspace(*cur)) ++cur;
  while (!isspace(*cur)) ++cur;
  char original = *cur;
  *cur = '\0';
  double val = atof(s);
  *cur = original;

#ifdef DEBUG
    printf("str: %s", s);
    printf("val: %.2lf\n", val);
#endif

  return val;
}

int main() {
  char s[10000];
  while (fgets(s, sizeof(s), stdin) != NULL) {
    printf("%.2lf\n", Parse(s));
  }
}

