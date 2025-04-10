#include "array.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  Array arr;
  Array y;
  Array z;
  printf("array declared.\n");
  bool success = arr.initialize(10, 4);  
  assert(success);
  bool success2 = y.initialize(3, 12);  
  assert(success2);
  bool success3 = z.initialize(0, 0);  
  assert(success3);
  printf("array intialized.\n");
  z = y;
  arr.print();
  y.print();
  z.print();
  z[2] = 5;
  printf("modified z[2]. now print again.\n");
  y.print();
  z.print();
  printf("current arr size(elements): %d\n", arr.size());
  printf("current y size(elements): %d\n", y.size());
  arr.append(8);
  arr.print();
  printf("current size(elements): %d\n", arr.size());
  arr.append(y);
  arr.print();
  arr[10] = 5;
  //arr[100] = 5;
  printf("printing y[2]: %d\nprinting arr[10]: %d\n", y[2], arr[10]);
  printf("current size(elements): %d\n", arr.size());
  // cleaning up
  arr.cleanup();
  y.cleanup();
  z.cleanup();

  // test code
  Array arr2;
  arr2.initialize(10, 5);
  arr2.print();

  Array rtoo;
  rtoo.initialize(0, 0);
  rtoo.print();
  rtoo = arr2;

  for(int i = 0; i < arr2.size(); i++){
      arr2[i] = i * 2;
  }
  printf("print arr2\n");
  arr2.print();

  printf("print rtoo\n");
  rtoo.print();

  arr2.cleanup();
  rtoo.cleanup();

  return 0;
}

