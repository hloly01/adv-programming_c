
#include "problem1.h"


int main(int argc, char* argv[]){
  int i;
  int return_;
  int test_values[17] = {1, 5, 12, 18, 19, 0, 17, 23, -3000, -24, 45, -1, 16.5, 22500, (17/3), -25, 0};
  
  for (i = 0; i < 17; i++){
    printf("\n\nfactors for %d are: ", test_values[i]);
    return_ = print_factors(test_values[i]);
    printf("returned: %d", return_);
    // print("\n");
  }
  printf("\n\nall done!\n");
  return(0);
}
