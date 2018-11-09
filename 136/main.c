#include <stdio.h>

typedef struct {
  char name[20];
  int id;
  char phone[10];
  float grade[4];
  int birth_year;
  int birth_month;
  int birth_day;
} Student;

int main() {
  char inName[85], outName[85]; 
  scanf("%s%s", inName, outName);
  FILE *in = fopen(inName, "rb");
  FILE *out = fopen(outName, "w");

  fprintf(out, "<table border=\"1\">\n<tbody>\n");
  Student student;
  while (fread(&student, sizeof(student), 1, in)) {
    fprintf(out, "<tr>\n");
    fprintf(out, "<td>%s</td>\n", student.name);
    fprintf(out, "<td>%d</td>\n", student.id);
    fprintf(out, "<td>%s</td>\n", student.phone);
    fprintf(out, "<td>%f, %f, %f, %f</td>\n", student.grade[0], student.grade[1], student.grade[2], student.grade[3]);
    fprintf(out, "<td>%d, %d, %d</td>\n", student.birth_year, student.birth_month, student.birth_day);
    fprintf(out, "</tr>\n");
  }
  fprintf(out, "</tbody>\n</table>\n");

  fclose(in);
  fclose(out);
}

