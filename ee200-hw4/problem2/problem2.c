#include <string.h>
#include "problem2.h"

void get_words(struct tm* pointer, char day[], char current_month[]){
  switch(pointer->tm_wday){
    case 0: 
      strcpy(day, "Sunday");
      break;
    case 1:
      strcpy(day, "Monday");
      break;
    case 2: 
      strcpy(day, "Tuesday");
      break;
    case 3: 
      strcpy(day, "Wednesday");
      break;
    case 4: 
      strcpy(day, "Thursday");
      break;
    case 5: 
      strcpy(day, "Friday");
      break;
    case 6: 
      strcpy(day, "Saturday");
      break;
    }
    switch(pointer->tm_mon){
    case 0: 
      strcpy(current_month, "January");
      break;
    case 1:
      strcpy(current_month, "February");
      break;
    case 2: 
      strcpy(current_month, "March");
      break;
    case 3: 
      strcpy(current_month, "April");
      break;
    case 4: 
      strcpy(current_month, "May");
      break;
    case 5: 
      strcpy(current_month, "June");
      break;
    case 6: 
      strcpy(current_month, "July");
      break;
    case 7:
      strcpy(current_month, "August");
      break;
    case 8: 
      strcpy(current_month, "September");
      break;
    case 9: 
      strcpy(current_month, "October");
      break;
    case 10: 
      strcpy(current_month, "November");
      break;
    case 11: 
      strcpy(current_month, "December");
      break;
    }
}

void print_time(time_t time_input){
  struct tm* tm_pointer;
  tm_pointer = gmtime(&time_input);
  char weekday[10];
  char month[10];
  get_words(tm_pointer, weekday, month);
  printf("%s, %s %02d, %04d %02d:%02d:%02d\n", weekday, month, tm_pointer->tm_mday, \
        (tm_pointer->tm_year + 1900), tm_pointer->tm_hour,tm_pointer->tm_min,tm_pointer->tm_sec);
}

