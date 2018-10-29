#include <stdio.h>

int DA, DB, DC;
int EA, EB, EC;
int FA, FB, FC;
int A, B, C;

int TestF(int nD, int nE, int nF) {
  if (nF == -1) return 0;  
  if (nD * DA + nE * EA + nF * FA == A &&
      nD * DB + nE * EB + nF * FB == B &&
      nD * DC + nE * EC + nF * FC == C) return 1;
  return TestF(nD, nE, nF - 1);
}

int TestE(int nD, int nE) {
  if (nE == -1) return 0;
  return TestF(nD, nE, 10) || TestE(nD, nE - 1);
}

int TestD(int nD) {
  if (nD == -1) return 0;
  return TestE(nD, 10) || TestD(nD - 1);
}

void TestCase(int n) {
  if (n == 0) return;
  scanf("%d%d%d", &A, &B, &C);
  if (TestD(10)) printf("yes\n");
  else printf("no\n");
  TestCase(n - 1);
}

int main() {
  int n;
  scanf("%d%d%d%d%d%d%d%d%d%d", &DA, &DB, &DC, &EA, &EB, &EC, &FA, &FB, &FC, &n);
  TestCase(n);
}

