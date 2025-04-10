#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>
#include <cassert>
#include <iostream>

template <typename T> class Array{
  public:
    // The function initialize(int size, int val) should set up the Array with storage for size elements, all initialized to val.
    Array();
    Array(int length, T val);
    Array(int length, T* values);
    Array(Array& copy); // copy constructor
    ~Array();
    int size() const; // return number of elements in array
    bool append(T x); // append x to end of array
    bool append(const Array& y);// append all of array y to end of array
    Array& operator=(const Array<T>& other); // create a deep copy here 
    Array operator+(const Array<T>& other); // add arrays of equal size 
    template <typename N>
    friend std::ostream& operator<<(std::ostream& op, const Array<N>& print); // write to stream
    T& operator[](const int index); // change to return indexed value 

  private:
     T* mArray;
     int msize;
};

// Constructors + destructor go here

template <typename T> Array<T>::Array(){
    msize = 0;
    mArray = NULL;
    printf("default constructor called.\n");
}

template <typename T> Array<T>::Array(int length, T val){
    printf("Array(int length, int val) constructor called.\n");
    int i;
    if (length >=0){
        mArray = (T*)calloc(length, sizeof(T)); 
        if (mArray != NULL){
            msize = length;
            if (msize > 0){
                for (i = 0; i < msize; i++) {
                    mArray[i] = val;
                }
            }
        }    
    }
}

template <typename T> Array<T>::Array(int length, T* values){
    printf("Array(int length, int* values) constructor called.\n");
    int i;
    if (length >=0){
        mArray = (T*)calloc(length, sizeof(T)); 
        if (mArray != NULL){
            msize = length;
            if (msize > 0){
                for (i = 0; i < msize; i++) {
                    mArray[i] = values[i];
                }
            }
        }    
    }
}

template <typename T> Array<T>::Array(Array& copy){
    printf("copy constructor called.\n");
    //if (copy != NULL){
        msize = copy.size();
        mArray = (T*)calloc(msize, sizeof(T)); 
        if (mArray != NULL){
            for (int i = 0; i < msize; i++){
                mArray[i] = copy.mArray[i];
            }
        }
    //}
}

template <typename T> Array<T>::~Array(){
    printf("destructor called.\n");
    free(mArray);
    msize = 0;
}

// Array management goes here

template <typename T> int Array<T>::size() const {return msize;} // return current size of array
template <typename T> bool Array<T>::append(const T x){
    int i;
    T* mArray_longer = (T*)realloc(mArray, msize*sizeof(T) + sizeof(T));
    if(mArray_longer != NULL){
        mArray = mArray_longer;
        msize++;
        mArray[msize - 1] = x;
        return 1;
    } else {printf("realloc failed.\n"); return 0;}
}

template <typename T> bool Array<T>::append(const Array& y){
    int more_elements = y.size();
    T* mArray_longer = (T*)realloc(mArray, (msize + more_elements)*sizeof(T));
    if(mArray_longer != NULL){
        int i;
        mArray = mArray_longer; 
        int start = msize; // subtract because of 0 indexing
        msize = msize + more_elements;
        for (i = 0; i < more_elements; i++) {
            mArray[start + i] = y.mArray[i];
        }
        return 1;
    } else {printf("realloc failed.\n"); return 0;}
}


// Array operations go here 

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& other){ // need a copy constuctor and to pass reference 
    int i;
    int size = other.size();
    if (msize > 0){free(mArray);}
    if(size > 0){
        mArray = (T*)calloc(size, sizeof(T)); 
        if (mArray != NULL){
            msize = size;
            for (i = 0; i < msize; i++){
                mArray[i] = other.mArray[i];
            }
        }
    } else {
        msize = 0;
        mArray = NULL;
    }
    return *this;
}

template <typename T> T& Array<T>::operator[](const int index){
    if (index >= 0 && index < msize){
        return mArray[index];
    } else {
        printf("error: index out of bounds.\n");
        exit(0);
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

#endif