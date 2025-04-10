#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>
#include <cassert>

class Array{
  public:
    // The function initialize(int size, int val) should set up the Array with storage for size elements, all initialized to val.
    bool initialize(int size, int val);
    void cleanup(); // clean things up 
    int size(); // return number of elements in array
    bool append(int x); // append x to end of array
    bool append(Array y);// append all of array y to end of array
    Array& operator=(const Array other); // create a deep copy here 
    int& operator[](const int index); // change to return indexed value 
    void print();

  private:
     int* mArray;
     int msize;
};

#endif
