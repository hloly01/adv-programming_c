#include <assert.h>
#include "problem2.h"


int main(int argc, char* argv[])
{
  int i;
  int result;
  int test_values[14] = {5, 1, 18, -24, 2, 43, -1, 16.5, 2250000, 22500, 225, (17/3), -25, 0};
  for (i = 0; i < 14; i++){
    printf("largest integer power of 2 <= %d is: ", test_values[i]);
    result = find_power(test_values[i]);
    printf("%d\n", result);
  }
  assert(result == 0); // make sure last array value is zero
  printf("\nall done!\n");
  return(0);
}

