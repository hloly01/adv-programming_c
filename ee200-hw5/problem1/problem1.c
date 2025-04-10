
#include "problem1.h"


void linspace(double* array, double min, double max, int n)
{
  int i;
  if (n > 0 && array != NULL) { // don't modify an array w/ zero or negative length or NULL
    double step = 0; // if length = 1, don't worry about step size (can't divide by zero)
    if(n > 1){
      step = (max - min) / (n - 1);
      }
    for (i = 0; i < n; i++) {
      *(array + i) = min + (step * i);
      //printf("array[%d] = %lf\n", i, *(array + i));
    }
  }
}

