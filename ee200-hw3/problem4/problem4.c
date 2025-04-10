#include "problem4.h"

double triangle_area(Triangle current, double* area){
  // identify ax, ay, bx, by, and cx, cy and define as doubles 

  // area eqn from here https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/
  *area = .5*fabs(current.a.x*(current.b.y-current.c.y) + current.b.x*(current.c.y-current.a.y)\
   + current.c.x*(current.a.y-current.b.y)); 
   return 0;
}

Triangle getLarger(Triangle first, Triangle second)
{

  // area eqn from here https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/

  // double area_first = triangle_area(first);
  double area_first;
  triangle_area(first, &area_first);
  double area_second; 
  triangle_area(second, &area_second);
  printf("first area is: %f\n", area_first);
  printf("second area is: %f\n", area_second);
  if (area_first >= area_second) {
    printf("returning first\n");
    return first;
  }
  else {
    printf("returning second\n");
    return second;
  }
}

