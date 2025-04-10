#include <stdlib.h>
#include <math.h>
#include "problem3.h"


double calculate(double x, char operation, double y)
{
  printf("\n");
  double result;
  switch (operation) {
    case '+':
      result = x + y;
      printf("%f + %f = %f\n", x, y, result);
      break;
    case '-':
      result = x - y;
      printf("%f - %f = %f\n", x, y, result);
      break;
    case '*':
      result = x * y;
      printf("%f * %f = %f\n", x, y, result);
      break;
    case '/':
      if (y == 0) {
        printf("error: cannot divide by zero.\n");
        return 0; 
        break;
      }
      result = x / y;
      printf("%f / %f = %f\n", x, y, result);
      break;
    case '^':
      result = pow(x,y);
      printf("%f ^ %f = %f\n", x, y, result);
      break;
    default:
      printf("error: this operator is invalid\n");
      return 0;
  }

  
  // Fill in this function

  // You'll want to replace this with something that returns a meaningful
  // result.
  return(result); 
}

