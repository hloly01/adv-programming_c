#include "array.h"

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
  std::cout << "short_arr: " << short_arr << " size(" << short_arr.size() << ")\n";
  std::cout << "test_char: " << test_char << " size(" << test_char.size() << ")\n";
  std::cout << "arr: " << arr << " size(" << arr.size() << ")\n";
  std::cout << "y: " << y << " size(" << y.size() << ")\n";
  std::cout << "w: " << w << " size(" << w.size() << ")\n";
  for(int i = 0; i < y.size(); i++){
      y[i] = i * 2;
      z[i] = i;
  }

  w.append(2.0);
  w.append(4.0);
  w.append(y);
  w = arr + y + z; 
  test_char = test_char + test_char2;
  //arr = arr + test_char;
  std::cout << "test_char: " << test_char << " size(" << test_char.size() << ")\n";
  std::cout << "arr: " << arr << " size(" << arr.size() << ")\n";
  std::cout << "y: " << y << " size(" << y.size() << ")\n";
  std::cout << "z: " << z << " size(" << z.size() << ")\n";
  std::cout << "w: " << w << " size(" << w.size() << ")\n";
  printf("current w size(elements): %d\n", w.size());
  short_arr = w;
  std::cout << "short_arr: " << short_arr << " size(" << short_arr.size() << ")\n";
  z[2] = 5;
  test_char[2] = 'b';
  printf("modified z[2] to %f. now print again.\n", z[2]);
  std::cout << "y: " << y << " size(" << y.size() << ")\n";
  std::cout << "z: " << z << " size(" << z.size() << ")\n";
  std::cout << "test_char: " << test_char << " size(" << test_char.size() << ")\n";
  arr.append(8);
  std::cout << "arr: " << arr << " size(" << arr.size() << ")\n";
  arr.append(y);
  std::cout << "arr: " << arr << " size(" << arr.size() << ")\n";
  arr[10] = 6;
  Array<float> failed_short_arr;
  w = failed_short_arr;
  short_arr = short_arr + arr;
  std::cout << "short_arr: " << short_arr << " size(" << short_arr.size() << ")\n";
  printf("no exceptions were thrown in this section! this is good.\n\n");  

  try { // OutOfBoundsException
    printf("trying to access something off the end of the array.\n");
    std::cout << "before:\t" << arr << " size(" << arr.size() << ")\n";
    arr[100] = 5;
  }
  catch (OutOfBoundsException& e){
    std::cout << "error: " << e.what() << "\n";
  }
  catch (std::exception& e){
    std::cout << "Caught unexpected exception! error: " << e.what() << "\n";
  }
  catch (...){
    std::cout << "Caught a non standard exception.\n" << "\n";
  }
  std::cout << "after:\t" << arr << " size(" << arr.size() << ")\n";

  try {
    printf("this should throw an InvalidSizeException. \n");
    Array<int> fail(-1,0);
  }
  catch (InvalidSizeException& e){
    std::cout << "error: " << e.what() << "\n";
  }
  catch (std::exception& e){
    std::cout << "Caught unexpected exception! error: " << e.what() << "\n";
  }
  catch (...){
    std::cout << "Caught a non standard exception." << "\n";
  }

  try {
    printf("this should throw an NullException. \n");
    Array<int> fail(10, (int*)NULL);
  }
  catch (NullException& e){
    std::cout << "error: " << e.what() << "\n";
  }
  catch (std::exception& e){
    std::cout << "Caught unexpected exception! error: " << e.what() << "\n";
  }
  catch (...){
    std::cout << "Caught a non standard exception.\n" << "\n";
  }

  return 0;
}