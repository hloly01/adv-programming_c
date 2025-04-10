#include <stdio.h>
#include <time.h>
/* problem1.c - Activity log */

int main(int argc, char* argv[])
{
  FILE *fp;
  fp = fopen("activity.tsv", "a");
  time_t epoch_time = time(NULL);
  if (argc < 3) {
    printf ("usage: not enough arguments were specified. \
    \nPlease enter an activity and duration in minutes (in that order). You may also include optional notes. \n");
    return(0);
  }
  fprintf(fp, "%ld\t", epoch_time);
  fprintf(fp, "%s\t", argv[1]);
  fprintf(fp, "%s\t", argv[2]);
  if (argc > 3){
    fprintf(fp, "%s\n", argv[3]);
  } else {fprintf(fp, "\n");}
  fclose(fp);

  return(0);
}

