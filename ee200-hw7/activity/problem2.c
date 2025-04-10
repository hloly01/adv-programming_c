#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i; 

void get_seconds(int* seconds, char* argv[]){
  char duration_string[100];
  int duration;
  char unit;
  int num_length;
  for (i = 0; argv[1][i] != '\0'; i++){
    if (argv[1][i] > 64) { // if a character, set unit and determine length of number. 
      num_length = i;
      unit = argv[1][i];
      break;
    }
  }
  for (i = 0; i < num_length; i++){
    duration_string[i] = argv[1][i];
  }
  duration = atoi(duration_string);
  // convert duration into seconds based on provided units
  switch (unit){
    case 'd':
      *seconds = duration*(60*60*24); 
      break;
    case 'w':
      *seconds = duration*(60*60*24*7);
      break;
    case 'y':
      *seconds = duration*(60*60*24*365);
      break;
    default:
      break;
  }
}

int main(int argc, char* argv[])
{
  // start by parsing string to split into integer and unit
  int seconds = 0;
  int summary = 0;
  if (argc < 2){
    printf("usage: not enough inputs. \
    \nPlease input a number and 'd', 'w', or 'y', for days, weeks or years respectively. \n");
    return 0;
  }
  get_seconds(&seconds, argv); // modifies seconds 
  if (seconds == 0){
    printf("usage: not enough inputs. \
    \nPlease input a number and 'd', 'w', or 'y', for days, weeks or years respectively. \n");
    return 0;
  }

  // now call the data file and check which lines are within the time range
  FILE *fp;
  fp = fopen("activity.tsv", "r");
  if (fp == NULL) {
    printf("error: file could not be read.\n");
    return 0;
  }
  char * line = NULL;
  char epoch_time_string[11];
  int epoch_time;
  time_t current;
  size_t len = 0;
  ssize_t read;
  char * pch;
  while ((read = getline(&line, &len, fp)) != -1) {
    for (i = 0; i < 11; i++) {epoch_time_string[i] = line[i];}
    epoch_time = atoi(epoch_time_string);
    current = time(NULL);
    pch = strtok (line," \t"); // break up line by tabs
    pch = strtok (NULL, " \t"); // skip two tabs
    pch = strtok (NULL, " \t");
    if (epoch_time >= current - seconds){
      summary = summary + atoi(pch);
    } 
  }

  printf("Total exercise: %d minutes\n", summary);
  return(0);
}

