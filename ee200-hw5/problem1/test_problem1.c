
#include "problem1.h"


int main(int argc, char* argv[])
{
  int n[] = {10, 0, 1, 10, 100, 5};
  double min[] = {-14, 0, 8, 0, 50, 5};
  double max[] = {-5, 10, 12, 4.5, 149, 1};
  double test_0[n[0]];
  double test_1[n[1]];
  double test_2[n[2]];
  double test_3[n[3]];
  double test_4[n[4]];
  double test_5[n[5]];
  linspace(test_0, min[0], max[0], n[0]);
  printf("\n");
  linspace(test_1, min[1], max[1], n[1]);
  printf("\n");
  linspace(test_2, min[2], max[2], n[2]);
  printf("\n");
  linspace(test_3, min[3], max[3], n[3]);
  printf("\n");
  linspace(test_4, min[4], max[4], n[4]);
  printf("\n");
  linspace(test_5, min[5], max[5], n[5]);
  printf("\n");
  linspace(NULL, min[6], max[6], n[6]);
  printf("\nall done!\n");
  return(0);
}

