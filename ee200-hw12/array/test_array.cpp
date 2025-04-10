#include "array.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // initializing arrays

  std::cout << "initializing arrays.\n";  
  Array<char> test_char(10, 'F');
  Array<char> test_char2(10, '(');
  Array<float> arr(10,10.0);
  Array<float> y(10,0.0);
  Array<float> z(10,0.0);
  Array<float> w(y);
  Array<float> short_arr;

  // modifying and printing 
  std::cout << "short_arr: " << short_arr << "\n";
  std::cout << "test_char: " << test_char << "\n";
  std::cout << "arr: " << arr << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "w: " << w << "\n";

  for(int i = 0; i < y.size(); i++){
      y[i] = i * 2;
      z[i] = i;
  }

  w = arr + y + z; 
  test_char = test_char + test_char2;
  //arr = arr + test_char;
  std::cout << "test_char: " << test_char << "\n";
  std::cout << "arr: " << arr << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
  std::cout << "w: " << w << "\n";
  printf("current w size(elements): %d\n", w.size());
  short_arr = w;
  std::cout << "short_arr: " << short_arr << "\n";

  z[2] = 5;
  test_char[2] = 'b';
  printf("modified z[2] to %f. now print again.\n", z[2]);
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
  std::cout << "test_char: " << test_char << "\n";
  printf("current arr size(elements): %d\n", arr.size());
  printf("current y size(elements): %d\n", y.size());
  arr.append(8);
  std::cout << "arr: " << arr << "\n";
  printf("current size(elements): %d\n", arr.size());
  arr.append(y);
  std::cout << "arr: " << arr << "\n";
  arr[10] = 6;
  //arr[100] = 5;
  printf("printing y[2]: %f\nprinting arr[10]: %f\n", y[2], arr[10]);
  printf("current size(elements): %d\n", arr.size());
  Array<float> failed_short_arr;
  w = failed_short_arr;
  short_arr = short_arr + arr;
  std::cout << "short_arr: " << short_arr << "\n";
  return 0;
}