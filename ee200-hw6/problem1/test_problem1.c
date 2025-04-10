#include "problem1.h"
#include <assert.h>

int main(int argc, char* argv[])
{
  char result[2]; 
  char test_invalid_char[3][3] = {"ABC", "def", "ghi"};
  char test_invalid_turns[3][3] = {"xx ", "   ", "   "};
  char test_board_cat[3][3] = {"XOX", "oxo", "oXo"};
  char test_board_incomplete[3][3] = {"xox", " xo", "oxo"};
  char test_board_vert[3][3] = {"XO ", "xo ", "X  "};
  char test_board_hor[3][3] = {"xox", "OoO", " xx"};
  char test_board_diag1[3][3] = {"xo ", "ox ", "  x"};
  char test_board_diag2[3][3] = {" xo", " o ", "ox "};
  *result = check_win(NULL);
  printf("result: %s\n", result);
  assert(*result == 0);
  *result = check_win(test_invalid_char);
  printf("result: %s\n", result);
  assert(*result == 0);
  *result = check_win(test_invalid_turns);
  printf("result: %s\n", result);
  assert(*result == 0);
  *result = check_win(test_board_cat);
  printf("result: %s\n", result);
  assert(*result == 46);
  *result = check_win(test_board_incomplete);
  printf("result: %s\n", result);
  assert(*result == 32);
  *result = check_win(test_board_vert);
  printf("result: %s\n", result);
  assert(*result == 120);
  *result = check_win(test_board_hor);
  printf("result: %s\n", result);
  assert(*result == 111);
  *result = check_win(test_board_diag1);
  printf("result: %s\n", result);
  assert(*result == 120);
  *result = check_win(test_board_diag2);
  printf("result: %s\n", result);
  assert(*result == 111);

  printf("\nall tests passed!\n");
  return(0);
}

