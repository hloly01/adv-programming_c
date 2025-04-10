
#include "problem2.h"


int* find_min(int* array, int n)
{
  int i;
  if (n < 1 || array == NULL){return NULL;}
  int min = *array;
  int min_index = 0;
  for (i = 0; i < n; i++){
    if (*(array + i) < min) {
      min = *(array + i);
      min_index = i;
    }
  }
  // printf("minimum is %d, index is %d\n", *(array + min_index), min_index);
  return (array + min_index);
}

