#include "problem2.h"

void lower(char* str)
{
  int i;
  int test;
  if (str != NULL) {
    for (i = 0; str[i] != '\0'; i++){
      test = str[i]; // get character as ASCII integer
      // if capital, add 32 to int value to convert to lowercase
      if (test <= 90 && test >= 65){
        *(str + i) = test + 32; 
      }
    }
  }
}