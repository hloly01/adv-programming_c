
#include "problem4.h"


int main(int argc, char* argv[])
{
  int i;
  const char* winner;
  const char *test[] = {"longish", "long", "a not actually short one", "goo", "onomatopoeia"};
  const char *test_1_null[] = {"longish", "long", NULL, "a not actually short one", "goo", NULL};
  const char *test_all_null[] = {NULL, NULL, NULL};
  
  winner = find_shortest(test, 5);
  for (i = 0; winner[i] != '\0'; i++){
    printf("%c", winner[i]);
  }
  printf("\n");
  
  winner = find_shortest(test_1_null, 6);
  for (i = 0; winner[i] != '\0'; i++){
    printf("%c", winner[i]);
  }
  printf("\n");
  
  winner = find_shortest(test_all_null, 3);
  find_shortest(NULL, 10);
  find_shortest(test, 0);
  printf("all done!\n");

  return(0);
}

