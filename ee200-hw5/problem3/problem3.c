
#include "problem3.h"
// what to do for sequences of same size? return the first one 

int* find_sequence(int* seq, int n)
{
  int winner = 0;
  int count = 0;
  int winner_count = 0;
  int i;
  if(n > 0 && seq != NULL){
    for (i = 1; i < n; i++) {
      if (*(seq + i) > *(seq + i -1)) {
        count++;
        if (count > winner_count) {
          winner_count = count;
          winner = i - count;
        }
      } else {count = 0;}
    }
    if (winner_count ==0) {return NULL;}
    return (seq + winner);
  } else {return NULL;}
}

