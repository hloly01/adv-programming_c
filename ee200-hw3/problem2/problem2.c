#include <stdlib.h>
#include "problem2.h"
// #include "../problem1/problem1.h"


int find_power(int n)
{
  // initialize integers i and count
  int i;
  int count = 0;
  if (n > 0) {
    for (i = 1; (i <= n); (i = i * 2)) {
    count++;
    }
  } else {
    return 0;
    }
  i = i/2;
  return i;
}

