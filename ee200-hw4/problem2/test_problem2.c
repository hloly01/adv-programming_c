#include "problem2.h"

int main(int argc, char* argv[])
{
  int i;
  time_t test[15] = {5, 1677279600, 1773406800, 1018213200, 1723492800, 1717534800, \
                    1723057200, 1717092000, 1435352400, 1725724800, 1722132000, \
                    1728431999, 1732392000, -6000, time(NULL)};
  for (i =0; i < 15; i++){
    print_time(test[i]);
  }
  // Put anything here that you think is appropriate to test your function
  // e.g, print_time(10);

  return(0);
}

