#include <stdlib.h>
#include <assert.h>
#include "problem5.h"

void print_random(int n, int max)
{
  int i;
  if (n > 0){
    for (i = 0; i < abs(n); i++) {
      if (i % 10 == 0){
        printf("\n");
      }
      int random = rand() % max;
      if (max<0){random = (-1)*random;}
      printf("%d ", random);
      assert(random != max);
  }
  }
  printf("\n\n");
}
