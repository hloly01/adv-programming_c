
#include "problem5.h"

int main(int argc, char* argv[])
{

  print_random(10,100000000);
  print_random(100,10);
  print_random(55, 55);
  // print_random(10000000,11000); // time consuming to run
  print_random(-12,-43);
  print_random(10, -10000000);
  print_random(0,10);
  print_random(0,0);
  printf("all tests passed!\n");

  // Put anything here that you think is appropriate to test your function

  return(0);
}

