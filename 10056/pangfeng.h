typedef struct {
  char name[35];
  int *scores;
} Row;

typedef struct {
  int dim_n;
  int idx;
  Row rows[1000000];
} ExamTable;

void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);
