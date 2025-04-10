#include <assert.h>
#include "problem2.h"


int main(int argc, char* argv[])
{
  int* minimum;
  int test_0[] = {5, 3, 7, 8, 1, 9, 11, 2};
  minimum = find_min(test_0, 8);
  printf("minimum for test_0 is: %d\n", *minimum);
  assert(*minimum == 1);
  int test_1[] = {0, 5, -3, 4, 8, 9, -2, 0};
  minimum = find_min(test_1, 8);
  printf("minimum for test_1 is: %d\n", *minimum);
  assert(*minimum == -3);
  minimum = find_min(test_1, 0);
  assert(minimum == NULL);
  minimum = find_min(test_1, -3);
  assert(minimum == NULL);
  int test_2[] = {0};
  minimum = find_min(test_2, 1);
  printf("minimum for test_2 is: %d\n", *minimum);
  assert(*minimum == 0);
  minimum = find_min(NULL, -3);
  assert(minimum == NULL);

  printf("all tests passed!\n");
  return(0);
}

