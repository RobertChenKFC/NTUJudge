#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[64];
  int height;
  int weight;
} Student;

int Comp(const void *pa, const void *pb) {
  Student a = *((Student*)pa), b = *((Student*)pb);
  float bmia = (float)a.weight / (a.height * a.height);
  float bmib = (float)b.weight / (b.height * b.height);
  if (bmia == bmib) {
    if (a.weight == b.weight) {
      if (a.height == b.height)
        return strcmp(a.name, b.name);
      return a.height - b.height;
    } 
    return a.weight - b.weight;
  }
  return (bmia - bmib) < 0 ? (-1) : 1;
}

Student students[100001];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s%d%d", students[i].name, &students[i].height, &students[i].weight);
  qsort(students, n, sizeof(Student), Comp);
  for (int i = 0; i < n; ++i)
    printf("%s %d %d\n", students[i].name, students[i].height, students[i].weight);
}

