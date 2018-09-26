#include "compute.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char name[64];
  int numCitations;
  int numPapers;
} Journal;

Journal journals[1025] = {0};

int comp(const void *a, const void *b) {
  return strcmp(((Journal*)a)->name, ((Journal*)b)->name);
}

void compute(paper P[], int N) {
  int numJournals = 0;
  for (int i = 0; i < N; ++i) {
    int found = 0;
    for (int j = 0; j < numJournals; ++j) {
      if (strcmp(P[i].journalName, journals[j].name) == 0) {
        found = 1;
        ++journals[j].numPapers;
        break;
      }
    } 
    if (!found) {
      strcpy(journals[numJournals].name, P[i].journalName);
      journals[numJournals].numPapers = 1;
      ++numJournals;
    }
  } 

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < P[i].numCitedPaper; ++j) {
      for (int k = 0; k < numJournals; ++k) {
        if (strcmp(P[P[i].citedPaperIndex[j]].journalName, journals[k].name) == 0) {
          ++journals[k].numCitations; 
          break;
        }
      } 
    } 
  }

  qsort(journals, numJournals, sizeof(Journal), comp);
  for (int i = 0; i < numJournals; ++i)
    printf("%s %d/%d\n", journals[i].name, journals[i].numCitations, journals[i].numPapers);
}
