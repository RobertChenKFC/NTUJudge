#include "placement.h"

#include <limits.h>

void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]) {
  switch (method) {
  case 0: {
    for (int i = 0; i < M; ++i) {
      result[i] = -1;
      for (int j = 0; j < N; ++j) {
        if (bucket[j] >= ball[i]) {
          bucket[j] -= ball[i];
          result[i] = j;
          break;
        } 
      } 
    } 
  } 
  break;
  case 1: {
    for (int i = 0; i < M; ++i) {
      result[i] = -1;
      int min = INT_MAX;
      int minj = -1;
      for (int j = 0; j < N; ++j) {
        if (bucket[j] >= ball[i]) {
          int cap = bucket[j] - ball[i];
          if (cap < min) {
            min = cap;
            minj = j;
            result[i] = j;
          }
        } 
      } 
      if (minj != -1)
        bucket[minj] = min;
    } 
  } 
  break;
  case 2: {
    for (int i = 0; i < M; ++i) {
      result[i] = -1;
      int max = INT_MIN;
      int maxj = -1;
      for (int j = 0; j < N; ++j) {
        if (bucket[j] >= ball[i]) {
          int cap = bucket[j] - ball[i];
          if (cap >= max) {
            max = cap;
            maxj = j;
            result[i] = j;
          }
        } 
      } 
      if (maxj != -1)
        bucket[maxj] = max;
    } 
  } 
  break;
  }
}
