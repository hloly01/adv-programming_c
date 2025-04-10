#include "array.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // initializing arrays

  std::cout << "initializing arrays.\n";  
  Array test;
  printf("current test size(elements): %d\n", test.size());
  Array arr(10,10);
  test.append(2);
  printf("current test size(elements): %d\n", test.size());
  Array y(10,0);
  Array z(10,0);
  Array w(y);

  // modifying and printing 
  for(int i = 0; i < y.size(); i++){
    y[i] = i * 2;
    z[i] = i;
  }

  std::cout << "arr: " << arr << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "w: " << w << "\n";

  w = arr + y + w; 
  std::cout << "arr: " << arr << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
  std::cout << "w: " << w << "\n";
  printf("current w size(elements): %d\n", w.size());

  z[2] = 5;
  printf("modified z[2]. now print again.\n");
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
  printf("current arr size(elements): %d\n", arr.size());
  printf("current y size(elements): %d\n", y.size());
  arr.append(8);
  std::cout << "arr: " << arr << "\n";
  printf("current size(elements): %d\n", arr.size());
  arr.append(y); 
  std::cout << "arr: " << arr << "\n";
  arr[10] = 5;
  //arr[100] = 5;
  printf("printing y[2]: %d\nprinting arr[10]: %d\n", y[2], arr[10]);
  printf("current size(elements): %d\n", arr.size());
  Array test_empty;

  return 0;
}