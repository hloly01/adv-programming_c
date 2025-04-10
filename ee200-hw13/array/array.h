#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>
#include <cassert>
#include <iostream>

class OutOfBoundsException: public std::exception{
    public:
    OutOfBoundsException(const char* msg) {mMsg = msg;}
    virtual const char* what() const throw() {return mMsg;}

    private:
    const char* mMsg;
};

class InvalidSizeException: public std::exception{
    public:
    InvalidSizeException(const char* msg) {mMsg = msg;}
    virtual const char* what() const throw() {return mMsg;}

    private:
    const char* mMsg;
};

class NullException: public std::exception{
    public:
    NullException(const char* msg) {mMsg = msg;}
    virtual const char* what() const throw() {return mMsg;}

    private:
    const char* mMsg;
};

template <typename T> 
class Array{
  public:
    // constructors and destructors
    Array();
    Array(int length, T val);
    Array(int length, T* values);
    Array(Array& copy); // copy constructor
    ~Array();
    // operator overlaods 
    Array& operator=(const Array<T>& other); // create a deep copy here 
    Array operator+(const Array<T>& other); // concatenate arrays of equal size 
    template <typename N>
    friend std::ostream& operator<<(std::ostream& op, const Array<N>& print); // write to stream
    T& operator[](const int index); 
    // array management 
    int size() const; // return number of elements in array
    bool append(T x); // append x to end of array
    bool append(const Array& y); // append all of array y to end of array


  private:
     T* mArray;
     int msize;
};

// Constructors + destructor go here

template <typename T> Array<T>::Array(){ // no exceptions
    msize = 0;
    mArray = NULL;
    //printf("default constructor called.\n");
}

template <typename T> Array<T>::Array(int length, T val){ // exceptions for neg length and failed new 
    printf("Array(int length, int val) constructor called.\n");
    int i;
    if (length >= 0){
    mArray = new T[length];
        msize = length;
        if (msize > 0){
            for (i = 0; i < msize; i++) {
                mArray[i] = val;
            }
        }
    } else {
        throw InvalidSizeException("array length cannot be negative!");
    }
}

template <typename T> Array<T>::Array(int length, T* values){ 
    //printf("Array(int length, int* values) constructor called.\n");
    int i;
    if (values != NULL){
        if (length >=0){
            mArray = new T[length];
            msize = length;
            if (msize > 0){
                for (i = 0; i < msize; i++) {
                    mArray[i] = values[i];
                }
            }   
        } else {
            throw InvalidSizeException("array length cannot be negative!");
        }
    } else {
        throw NullException("cannot copy a NULL array.");
    }
}

template <typename T> Array<T>::Array(Array& copy){
    //printf("copy constructor called.\n");
    msize = copy.size();
    mArray = new T[msize];
    for (int i = 0; i < msize; i++){
        mArray[i] = copy.mArray[i];
    }    
}

template <typename T> Array<T>::~Array(){
    printf("destructor called.\n");
    delete[] mArray;
    msize = 0;
}

// Array operations go here 

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& other){
    int i;
    int size = other.size();
    if(size > 0){
        T* new_mem = new T[size];
        if (msize > 0){delete[] mArray;}
        mArray = new_mem;
        msize = size;
        for (i = 0; i < msize; i++){
            mArray[i] = other.mArray[i];
        }
    } else {
        if (msize > 0){delete[] mArray;}
        msize = 0;
        mArray = NULL;
    }
    return *this;
}

template <typename T> T& Array<T>::operator[](const int index){
    if (index >= 0 && index < msize){
        return mArray[index];
    } else {
        throw OutOfBoundsException("array out of bounds!");
    }
}

template <typename T> Array<T> Array<T>::operator+(const Array<T>& other){
    Array cat_array;
    cat_array.append(*this);
    cat_array.append(other);
    return cat_array;
}

template <typename T> std::ostream& operator<<(std::ostream& op, const Array<T>& print) {
    op << "[";
    if (print.msize != 0){
        for (int i = 0; i < print.msize; i++){
            if(i != 0){op << ", ";}
            op << print.mArray[i];
        }  
    }
    op << "]";
    return op;
}

// Array management goes here

template <typename T> int Array<T>::size() const {return msize;} // return current size of array
template <typename T> bool Array<T>::append(const T x){ // working
    int i;
    T* mArray_longer = new T[msize + 1];
    for (i = 0; i < msize; i++){ // copy in old data
        mArray_longer[i] = mArray[i];
    }
    mArray_longer[msize] = x;
    delete[] mArray; // clear existing memory of mArray
    mArray = mArray_longer; // mArray_longer is not an Array class and therefore the operator overload does not work
    msize++;
    return 1;
}

template <typename T> bool Array<T>::append(const Array& y){
    int i;
    int more_elements = y.size();
    T* mArray_longer = new T[msize + more_elements];
    for (i = 0; i < msize; i++){ // copy in old data
        mArray_longer[i] = mArray[i];
    }
    int start = msize; // subtract because of 0 indexing    
    for (i = 0; i < more_elements; i++) {
        mArray_longer[start + i] = y.mArray[i];
    }
    delete[] mArray;
    mArray = mArray_longer; 
    msize = msize + more_elements;
    return 1;
}

#endif