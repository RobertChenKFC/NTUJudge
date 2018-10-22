#include <stdio.h>
#include <string.h>

enum {
  STOP,
  GOTO,
  CONDITION,
  PRINT,
  ASSIGNMENT
};

enum {
  EQ,
  NEQ,
  G,
  L,
  GEQ,
  LEQ,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD
};

typedef struct {
  int type;
  int lhs;
  int rhs1, rhs2;
  int operand;
  int lineNum;
} Instruction;

int FindIndex(char *name, char names[100][10], int numVariables) {
  for (int i = 0; i < numVariables; ++i)
    if (strcmp(name, names[i]) == 0) return i; 
  return -1;
}

int FindConditionOperand(char *str) {
  if (strcmp(str, "==") == 0) return EQ;
  if (strcmp(str, "!=") == 0) return NEQ;
  if (strcmp(str, ">") == 0) return G;
  if (strcmp(str, "<") == 0) return L;
  if (strcmp(str, ">=") == 0) return GEQ;
  if (strcmp(str, "<=") == 0) return LEQ;
  return -1;
}

int FindArithmeticOperand(char *str) {
  if (strcmp(str, "+") == 0) return ADD;
  if (strcmp(str, "-") == 0) return SUB;
  if (strcmp(str, "*") == 0) return MUL;
  if (strcmp(str, "/") == 0) return DIV;
  if (strcmp(str, "%") == 0) return MOD;
  return -1;
}

int Execute(int lineNum, Instruction instruction, int *variables) {
  switch (instruction.type) {
  case GOTO:
    return instruction.lineNum;
  case CONDITION: {
    int condition;
    switch (instruction.operand) {
    case EQ:
#ifdef DEBUG
      printf("%d: IF %d == %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] == variables[instruction.rhs2];
      break;
    case NEQ:
#ifdef DEBUG
      printf("%d: IF %d != %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] != variables[instruction.rhs2];
      break;
    case G:
#ifdef DEBUG
      printf("%d: IF %d > %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] > variables[instruction.rhs2];
      break;
    case L:
#ifdef DEBUG
      printf("%d: IF %d < %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] < variables[instruction.rhs2];
      break;
    case GEQ:
#ifdef DEBUG
      printf("%d: IF %d >= %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] >= variables[instruction.rhs2];
      break;
    case LEQ:
#ifdef DEBUG
      printf("%d: IF %d <= %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      condition = variables[instruction.rhs1] <= variables[instruction.rhs2];
      break;
    }
    return condition ? instruction.lineNum : (lineNum + 1);
  }
  case PRINT:
    printf("%d\n", variables[instruction.rhs1]);
    return lineNum + 1;
  case ASSIGNMENT:
    switch (instruction.operand) {
    case ADD:
#ifdef DEBUG
      printf("%d: %d + %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      variables[instruction.lhs] = variables[instruction.rhs1] + variables[instruction.rhs2];
      break;
    case SUB:
#ifdef DEBUG
      printf("%d: %d - %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      variables[instruction.lhs] = variables[instruction.rhs1] - variables[instruction.rhs2];
      break;
    case MUL:
#ifdef DEBUG
      printf("%d: %d * %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      variables[instruction.lhs] = variables[instruction.rhs1] * variables[instruction.rhs2];
      break;
    case DIV:
#ifdef DEBUG
      printf("%d: %d / %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      variables[instruction.lhs] = variables[instruction.rhs1] / variables[instruction.rhs2];
      break;
    case MOD:
#ifdef DEBUG
      printf("%d: %d MOD %d\n", lineNum, variables[instruction.rhs1], variables[instruction.rhs2]);
#endif

      variables[instruction.lhs] = variables[instruction.rhs1] % variables[instruction.rhs2];
      break;
    }
    return lineNum + 1;
  }
}

int main() {
  char buf[100];
  int variables[100];
  char names[100][10];
  Instruction instructions[1001];

  int numVariables = 0;
  while (1) {
    scanf("%s", names[numVariables]);
    if (strcmp(names[numVariables], "END") == 0) break;
    scanf("%s%d", buf, &variables[numVariables++]);
  }

#ifdef DEBUG
   printf("Variables done\n");
#endif

  int idx = 1;
  while (scanf("%s", buf) != EOF) {
    if (strcmp(buf, "STOP") == 0) {
#ifdef DEBUG
      printf("STOP\n");
#endif

      instructions[idx].type = STOP; 
    } else if (strcmp(buf, "GOTO") == 0) {
#ifdef DEBUG
      printf("GOTO\n");
#endif

      instructions[idx].type = GOTO; 
      scanf("%d", &instructions[idx].lineNum);
    } else if (strcmp(buf, "IF") == 0) {
#ifdef DEBUG
      printf("IF\n");
#endif

      instructions[idx].type = CONDITION; 
      scanf("%s", buf);
      instructions[idx].rhs1 = FindIndex(buf, names, numVariables);
      scanf("%s", buf);
      instructions[idx].operand = FindConditionOperand(buf);
      scanf("%s", buf);
      instructions[idx].rhs2 = FindIndex(buf, names, numVariables);
      scanf("%s%d", buf, &instructions[idx].lineNum);
    } else if (strcmp(buf, "PRINT") == 0) {
#ifdef DEBUG
      printf("PRINT\n");
#endif

      instructions[idx].type = PRINT;
      scanf("%s", buf);
      instructions[idx].rhs1 = FindIndex(buf, names, numVariables);
    } else {
#ifdef DEBUG
      printf("ASSIGNMENT\n");
#endif

      instructions[idx].type = ASSIGNMENT;
      instructions[idx].lhs = FindIndex(buf, names, numVariables);
#ifdef DEBUG
      printf("Read in %s (should be a variable)\n", buf);
#endif

      scanf("%s%s", buf, buf);
      instructions[idx].rhs1 = FindIndex(buf, names, numVariables);
#ifdef DEBUG
      printf("Read in %s (should be a variable)\n", buf);
#endif

      scanf("%s", buf);
      instructions[idx].operand = FindArithmeticOperand(buf);
#ifdef DEBUG
      printf("Read in %s (should be an operand)\n", buf);
#endif

      scanf("%s", buf);
      instructions[idx].rhs2 = FindIndex(buf, names, numVariables);
#ifdef DEBUG
      printf("Read in %s (should be a variable)\n", buf);
#endif
    }
    ++idx;
  } 

  idx = 1;
  while (1) {
    if (instructions[idx].type == STOP) break;
    idx = Execute(idx, instructions[idx], variables);

#ifdef DEBUG
    printf("Going to line %d\n", idx);
#endif
  }
}

