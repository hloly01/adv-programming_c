#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate(double x, char operation, double y);

double calculate(double x, char operation, double y){
  double result;
  switch (operation) {
    case '+':
      result = x + y;
      printf("%f", result);
      break;
    case '-':
      result = x - y;
      printf("%f", result);
      break;
    case '*':
      result = x * y;
      printf("%f", result);
      break;
    case '/':
      if (y == 0) {
        printf("error: cannot divide by zero.\n");
        return 0; 
        break;
      }
      result = x / y;
      printf("%f", result);
      break;
    case '^':
      result = pow(x,y);
      printf("%f", result);
      break;
    default:
      printf("error: this equation is invalid\n");
      return 0;
  }

  return(result); 
}

int main(int argc, char* argv[])
{
  double x1;
  double y1;
  char operation;
  double result;
  if (argc > 1) {
    x1 = atof(argv[1]);
    operation = *argv[2];
    y1 = atof(argv[3]);
    result = calculate(x1, operation,y1);
  }
  scanf("%lf %c %lf", &x1, &operation, &y1);
  result = calculate(x1, operation,y1);
  return(result);
}

