#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct Task {
  int machine;
  int time;
} Task;

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int nMachines, nJobs;
  scanf("%d%d", &nMachines, &nJobs);

  Task tasks[nJobs][500];
  memset(tasks, 0, sizeof(tasks));
  int nTotalTasks = 0;
  int start[nJobs];
  for (int i = 0; i < nJobs; ++i) {
    int nTasks;
    scanf("%d%d", &start[i], &nTasks);
    for (int j = 0; j < nTasks; ++j) {
      scanf("%d", &tasks[i][j].machine);
      scanf("%d", &tasks[i][j].time); 
      ++nTotalTasks;
    }
  }

  int curTasks[nJobs];
  memset(curTasks, 0, sizeof(curTasks));
  int ready[nMachines];
  memset(ready, 0, sizeof(ready));
  int nTasksCompleted = 0;
  while (nTasksCompleted < nTotalTasks) {
    int minCompletion = INT_MAX;
    int chosenJob;
    for (int i = 0; i < nJobs; ++i) {
      Task curTask = tasks[i][curTasks[i]];
      if (curTask.time == 0)
        continue;
      int completion = max(ready[curTask.machine], start[i]) + curTask.time;
      if (completion < minCompletion) {
        minCompletion = completion;
        chosenJob = i;
      }
    }
    Task chosenTask = tasks[chosenJob][curTasks[chosenJob]];
    start[chosenJob] = ready[chosenTask.machine] = minCompletion;
    ++curTasks[chosenJob];
    ++nTasksCompleted;
  }

  for (int i = 0; i < nJobs; ++i)
    printf("%d\n", start[i]);
}
