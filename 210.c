#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char lastname[85];
  char firstname[85];
  char id[85];
  int salary;
  int age;
} Datum;

enum {
  LAST_NAME,
  FIRST_NAME,
  ID,
  SALARY,
  AGE,
  WHERE
};

#define IS_COMPARING_STRING(X) ((X) <= ID)

enum {
  EQ,
  NEQ,
  G,
  L
};

int ToField(char *s) {
  switch (s[0]) {
  case 'l':
    return LAST_NAME;
  case 'f':
    return FIRST_NAME;
  case 'I':
    return ID;
  case 's':
    return SALARY;
  case 'a':
    return AGE;
  case 'w':
    return WHERE;
  }
}

int ToOperator(char *s) {
  switch (s[0]) {
  case '=':
    return EQ;
  case '!':
    return NEQ;
  case '>':
    return G;
  case '<':
    return L;
  }  
}

char* SelectStringField(Datum *datum, int field) {
  switch (field) {
  case LAST_NAME:
    return datum->lastname;
  case FIRST_NAME:
    return datum->firstname;
  case ID:
    return datum->id;
  }
}

int SelectNumberField(Datum *datum, int field) {
  switch (field) {
  case SALARY:
    return datum->salary;
  case AGE:
    return datum->age;
  }
}

int MatchesCondition(Datum *datum, int isComparingString, int lhs, int operator, char *rhsString, int rhsNumber) {
  if (isComparingString) {
    switch (operator) {
    case EQ:
      return strcmp(SelectStringField(datum, lhs), rhsString) == 0;
    case NEQ:
      return strcmp(SelectStringField(datum, lhs), rhsString) != 0;
    } 
  } else {
    switch (operator) {
    case EQ:
      return SelectNumberField(datum, lhs) == rhsNumber;
    case G:
      return SelectNumberField(datum, lhs) > rhsNumber;
    case L:
      return SelectNumberField(datum, lhs) < rhsNumber;
    } 
  }
}

void PrintDatum(Datum *datum, int fields[], int numFields) {
  for (int i = 0; i < numFields; ++i) {
    if (i != 0) printf(" ");
    if (IS_COMPARING_STRING(fields[i]))
      printf("%s", SelectStringField(datum, fields[i])); 
    else
      printf("%d", SelectNumberField(datum, fields[i]));
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  Datum data[55];
  for (int i = 0; i < n; ++i) {
    Datum *datum = &data[i];
    scanf("%s%s%s%d%d", datum->lastname, datum->firstname, datum->id, &datum->salary, &datum->age);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    char buf[85];
    scanf("%s", buf);
    int fields[10];
    int numFields = 0;
    int lhs, operator;
    int isComparingString;
    char rhsString[85];
    int rhsNumber;
    while (1) {
      scanf("%s", buf);
      int field = ToField(buf);
      if (field == WHERE) {
        scanf("%s", buf);
        lhs = ToField(buf);      
        isComparingString = IS_COMPARING_STRING(lhs);
        scanf("%s", buf);
        operator = ToOperator(buf);
        if (isComparingString) scanf("%s", rhsString);
        else scanf("%d", &rhsNumber);
        break;
      } else {
        fields[numFields++] = field; 
      }
    }
    for (int i = 0; i < n; ++i) {
      if (MatchesCondition(&data[i], isComparingString, lhs, operator, rhsString, rhsNumber))
        PrintDatum(&data[i], fields, numFields);
    }
  }
}

