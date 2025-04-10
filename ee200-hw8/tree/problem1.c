#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <linux/limits.h>
#include <assert.h>

int i;

void open_and_print(char directory[], int* spaces){
  DIR *directory_pointer;
  char slash[] = "/";
  struct dirent *current_dir;
  ssize_t space = sizeof(char)*strlen(directory);
  char* new_directory = (char*)malloc(space);
  int reset = *spaces;
  strcpy(new_directory, directory);
  directory_pointer = opendir(directory);
  if (directory_pointer != NULL){
    *spaces = *spaces + 1;
    while ((current_dir = readdir(directory_pointer)) != NULL){
      if (current_dir->d_name[0] != 46) {
        ssize_t more_space = sizeof(char)*strlen(current_dir->d_name);
        char* new_directory_longer = (char*)realloc(new_directory, space + more_space + 20);
        if(new_directory_longer != NULL){
          new_directory = new_directory_longer;
          strcpy(new_directory, directory);
          for (i = 0; i < *spaces; i++){
            printf("    ");
          }
          printf("%s\n", current_dir->d_name);
          strcat(new_directory, slash);
          strcat(new_directory, current_dir->d_name);
          open_and_print(new_directory, spaces);
        }
      }
    }
    *spaces = reset;
    closedir(directory_pointer);
  }
  free(new_directory);
}
int main(int argc, char* argv[])
{
  char directory_name[PATH_MAX];
  int indents = 0;
  if (argc == 2) {
    char* directory_name = (char*)malloc(sizeof(char)*strlen(argv[1]));
    if (directory_name == NULL) {
      printf("reallocation failed.\n");
      return 0;
    }
    strcpy(directory_name, argv[1]);
    printf("%s\n", directory_name);
    open_and_print(directory_name, &indents);
  } else {
    getcwd(directory_name, sizeof(directory_name));
    printf(".\n");
    open_and_print(directory_name, &indents);
  }
  return(0);
}
