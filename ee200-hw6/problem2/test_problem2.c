#include <assert.h>
#include "problem2.h"


int main(int argc, char* argv[])
{
  int i;
  char test_1[] = "UP -> low: ABCDEFGHIJKLMNOPQRSTUVWXYZ! and some #'s [123456]";
  lower(test_1);
  int check;
  for (i = 0; test_1[i] != '\0'; i++){
    printf("%c", test_1[i]);
    check = test_1[i];
    assert(check < 65 || check > 90);
  }
  printf("\n");
  
  lower(NULL);

  printf("all tests passed!\n");
  return(0);
}

