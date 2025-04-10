
#include "problem1.h"

int i;
int j;
char x[] = "x";
char o[] = "o";
char blank[] = " ";

bool check(char* condition, char* blank){
  if (condition[0] == condition[1] && condition[1] == condition[2] && condition[0] != blank[0]){
    return 1;
  } else {return 0;}
}

bool check_valid(char board[3][3]){ // 0 is invalid, 1 is valid
  int count_x = 0;
  int count_o = 0;
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      board[i][j] = tolower(board[i][j]);
      if (board[i][j] == x[0]){count_x++;}
      if (board[i][j] == o[0]){count_o++;}
      if (board[i][j] != x[0] && board[i][j] != o[0] && board[i][j] != blank[0]) {return 0;}
    }
  }
  if (abs(count_o - count_x) > 1){
    return 0;
    } else {return 1;}
}
char check_win(char board[3][3])
{
  // win possiblities: 
  // board[i] = XXX                               Vertical win
  // board[i][0] = XXX                            Horizontal win
  // board[i][i] = XXX                            Diagonal win V1 
  // board[0][2] == board[1][1] == board[2][0]    Diagonal win in other direction

  // clarifying questions:
  // x and X both valid? or only lowercase
  // talk about assumptions, is this going turn by turn so only one win is possible at a time?

  bool valid_board;
  char check_vert[] = "   ";
  char check_hor[] = "   ";
  char check_diag[] = "   ";
  char invalid[] = "\0";
  char cat[] = ".";
  bool still_going = 0;
  if (board != NULL){
    valid_board = check_valid(board);
  } else {return *invalid;}
  if (valid_board){
    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        if (board[i][j] == blank[0] || board[j][i] == blank[0] || board[j][j] == blank[0]) {still_going = 1;}
        check_hor[j] = board[i][j];
        check_vert[j] = board[j][i];
        check_diag[j] = board[j][j];
      }
      if (check(check_hor, blank)) {return check_hor[0];}
      if (check(check_vert, blank)){return check_vert[0];}
      if (check(check_diag, blank)){return check_diag[0];}
      if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != blank[0]) {
        return board[1][1];
      }
    }
    if (still_going) {return *blank;} else {return *cat;}
  } else {return(*invalid);} 
}

