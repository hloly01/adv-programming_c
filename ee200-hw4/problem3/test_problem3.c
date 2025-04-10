
#include "problem3.h"

int main(int argc, char* argv[])
{
 // Define first triangle
  double x; double y;
  Point first_a = {.x = 0, .y = 0}; // test cases x = (1,112,0), y = (1,11,0)
  Point first_b = {.x = 5, .y = 0}; // test cases x = (1,2,0,5), y = (2,22,0)
  Point first_c = {.x = 5, .y = 2}; // test cases x = (2,0,5), y = (3,332,0,2)
  Triangle first = {.a = first_a, .b = first_b, .c = first_c};
  // Define second triangle 
  Point second_a = {.x = .7, .y = 1.1111}; // test cases x = (1,4, (7/9)), y = (4, (4/3))
  Point second_b = {.x = .3, .y = .6}; // test cases x = (3, (3/10)), y = (4,3, (3/5))
  Point second_c = {.x = 2.5, .y = -.2222}; // test cases x = (3,5, (5/2)), y = (6,0,5,-5, (-2/11))
  Triangle second = {.a = second_a, .b = second_b, .c = second_c};
  //Triangle second = {.a =1};
  // coordinate print statement
  getLarger(&first, &second);

  Point first_a_ = {.x = 0, .y = 0}; 
  Point first_b_ = {.x = 5, .y = 0};
  Point first_c_ = {.x = 5, .y = 2}; 
  Triangle first_ = {.a = first_a_, .b = first_b_, .c = first_c_};
  // Define second triangle 
  Point second_a_ = {.x = (0), .y = (0)}; 
  Point second_b_ = {.x = (0), .y = (5)}; 
  Point second_c_ = {.x = (2), .y = (5)}; 
  Triangle second_ = {.a = second_a_, .b = second_b_, .c = second_c_};

  getLarger(&first_, &second_);

  Point first_a_2 = {.x = 0, .y = 0}; 
  Point first_b_2 = {.x = 5, .y = 5};
  Point first_c_2 = {.x = 2, .y = 2}; 
  Triangle first_2 = {.a = first_a_2, .b = first_b_2, .c = first_c_2};
  // Define second triangle 
  Point second_a_2 = {.x = 0, .y = 0}; 
  Point second_b_2 = {.x = -2, .y = 0}; 
  Point second_c_2 = {.x = -2, .y = -6}; 
  Triangle second_2 = {.a = second_a_2, .b = second_b_2, .c = second_c_2};

  getLarger(&first_2, &second_2);
  getLarger(NULL, &second);
  Triangle *ans = getLarger(&first, NULL);
  return(0);
}

