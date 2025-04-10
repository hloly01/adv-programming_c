#include <assert.h>
#include "problem3.h"


int main(int argc, char* argv[])
{
  double ans;
  ans = calculate(15,'+', 7);
  assert(ans == 22); 
  ans = calculate(22000,'-', 11000);
  ans = calculate(500000000,'/', 2);
  ans = calculate(8,'/', 0);
  assert(ans == 0);
  ans = calculate(2,'^', 3);
  assert(ans == 8); 
  ans = calculate(7,'*', 9);
  assert(ans == 63); 
  ans = calculate(5, '-', -8);
  assert(ans == 13); 
  ans = calculate(-5, '*', -6);
  assert(ans == 30); 
  ans = calculate(14, '*', -3);
  assert(ans == -42); 
  ans = calculate(4, '=', 3);
  assert(ans == 0);
  ans = calculate(2, '^', 0);
  assert(ans == 1); 
  ans = calculate(19,'^', 4);
  ans = calculate(0, '^', 0);
  assert(ans == 1); 
  ans = calculate(0, '^', 5);
  assert(ans == 0); 

  printf("\nall tests passed!\n\n");
  return(0);
}

