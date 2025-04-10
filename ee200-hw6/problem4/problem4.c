#include <limits.h>
#include "problem4.h"

const char* find_shortest(const char * const * strings, int len)
{
  int i;
  int j;
  int count = 0;
  int len_shortest = INT_MAX;
  const char* shortest;
  if (strings != NULL && len != 0) { 
    for (i = 0; i < len; i++){ // loop through every string
      count = 0;
      if (strings[i] != NULL) {
        for (j = 0; strings[i][j] != '\0'; j++){ // determine length of string
          count++;
          if (count > len_shortest){break;} // give up if it isn't going to win
        }
        if (count < len_shortest) {
          len_shortest = count;
          shortest = strings[i];
        }
      }
    }
    if (len_shortest != INT_MAX) {
      return shortest;
    } else {return NULL;}
  }
  return NULL;
}

