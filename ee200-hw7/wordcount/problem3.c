#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* problem3.c - Word counting */

void args_switch_case(char argument, bool* bool_lines, bool* bool_words, bool* bool_chars){
  switch(argument){
    case 'l':
      *bool_lines = 1;
      break;
    case 'w': 
      *bool_words = 1;
      break;
    case 'c':
      *bool_chars = 1;
      break;
    default:
      printf("invalid argument.\n");
  }
}

int main(int argc, char* argv[])
{
  int i;
  if (argc < 2) {
    printf("error: not enough inputs. \n");
    return 0;
    }
  FILE *fp;
  fp = fopen(argv[argc-1], "r");
  if (fp == NULL) {
    printf("file could not be read.\n");
    return 0;
  }
  size_t len = 0;
  ssize_t read;
  char* line = NULL;
  char* pch;
  int lines = 0;
  bool bool_lines = 0;
  int words = 0;
  bool bool_words = 0;
  int chars = 0;
  bool bool_chars = 0;
  char arg[] = "d";
  while ((read = getline(&line, &len, fp)) != -1) { // goes through every line in file
    lines++;
    chars = chars + read;
    pch = strtok (line," \n\t"); // break up line by spaces, tabs, and enter
    while (pch != NULL){
      words++;
      pch = strtok (NULL, " \n\t");
    }
    pch = strtok (NULL, " \t");
  } 

  for (i = 1; i < argc-1; i++){
    *arg = argv[i][1];
    args_switch_case(*arg, &bool_lines, &bool_words, &bool_chars);
  }
  if (bool_lines) {printf("%d ", lines);}
  if (bool_words) {printf("%d ", words);}
  if (bool_chars) {printf("%d ", chars);}
  if (arg[0] == 100){printf("%d %d %d ", lines, words, chars);}
  printf("%s\n", argv[argc-1]);
  if (argc > 5) {printf("error: too many inputs.\n");}
  return(0);
}

