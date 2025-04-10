
#include "problem3.h"

void find_frequency(const char* str, int len, unsigned int histogram[26])
{
  int i;
  int j;
  int lower = 97;
  int upper = 65;
  int count;
  int ascii;
  if (str != NULL) {
    for (i = 0; i < 26; i++){
      count = 0;
      for (j = 0; j < len; j++){
        ascii = str[j];
        if (ascii == lower || ascii == upper) {count++;}
      }
      lower++;
      upper++;
      histogram[i] = count;
    }
  }
}

