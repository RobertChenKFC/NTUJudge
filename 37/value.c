#include "value.h"

int Gcd(int a, int b) {
  if (a >= b) {
    int r = a % b;
    if (r == 0) return b;
    return Gcd(b, r);
  }
  int r = b % a;
  if (r == 0) return a;
  return Gcd(a, r);
}

int value(int type, int width, int height, int length) {
  if (type != 79 && type != 47 && type != 29 && type != 82 && type != 26 && type != 22) return -1;
  if (width <= 0 || height <= 0 || length <= 0) return -2;
  int dim = Gcd(Gcd(width, height), length);
  int vol = dim * dim * dim;
  int volSq = vol * vol;
  int total = (width / dim) * (height / dim) * (length / dim) * volSq;
  switch (type) {
  case 79:  
    return total * 30; 
  case 47:  
    return total * 10; 
  case 29:  
    return total * 4; 
  case 82:  
    return total * 5; 
  case 26:  
    return total * 3; 
  case 22:  
    return total * 9; 
  }
}

