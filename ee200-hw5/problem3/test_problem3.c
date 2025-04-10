#include <assert.h>
#include "problem3.h"


int main(int argc, char* argv[])
{
  int* largest_seq;
  int test_0[] = {5, 3, 7, 8, 1, 9, 11, 12, 2, 5, 6, 0};
  int test_1[] = {0, 5, -3, 4, 8, 9, -2, 0};
  int test_2[] = {1, 2, 3, 3, 2, 4, 5, 0};
  int test_3[] = {5, 4, 3, 2, 1, 0};
  int test_4[] = {0};
  largest_seq = find_sequence(test_0, 12);
  printf("start of largest sequence for test_0 is: %d\n", *largest_seq);
  assert(*largest_seq == 1);
  largest_seq = find_sequence(test_1, 8);
  printf("start of largest sequence for test_1 is: %d\n", *largest_seq);
  assert(*largest_seq == -3);
  largest_seq = find_sequence(test_2, 8);
  printf("start of largest sequence for test_2 is: %d\n", *largest_seq);
  assert(*largest_seq == 1);
  largest_seq = find_sequence(test_3, 6);
  assert(largest_seq == NULL);
  largest_seq = find_sequence(test_1, 0);
  assert(largest_seq == NULL);
  largest_seq = find_sequence(test_1, -3);
  assert(largest_seq == NULL);
  largest_seq = find_sequence(test_4, 1);
  assert(largest_seq == NULL);
  largest_seq = find_sequence(NULL, 3);
  assert(largest_seq == NULL);

  printf("all tests passed!\n");

  return(0);
}

