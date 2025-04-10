#include "array.h"

// Constructors + destructor go here

Array::Array(){
    msize = 0;
    mArray = NULL;
    printf("default constructor called.\n");
}

Array::Array(int length, int val){
    printf("Array(int length, int val) constructor called.\n");
    int i;
    if (length >=0){
        mArray = (int*)calloc(length, sizeof(int)); 
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

Array::Array(int length, int* values){
    printf("Array(int length, int* values) constructor called.\n");
    int i;
    if (length >=0){
        mArray = (int*)calloc(length, sizeof(int)); 
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

Array::Array(Array& copy){
    printf("copy constructor called.\n");
    //if (copy != NULL){
        msize = copy.size();
        mArray = (int*)calloc(msize, sizeof(int)); 
        if (mArray != NULL){
            for (int i = 0; i < msize; i++){
                mArray[i] = copy.mArray[i];
            }
        }
    //}
}

Array::~Array(){
    printf("destructor called.\n");
    free(mArray);
}

// Array management goes here

int Array::size(){return msize;} // return current size of array
bool Array::append(const int x){
    int i;
    int* mArray_longer = (int*)realloc(mArray, msize*sizeof(int) + sizeof(int));
    if(mArray_longer != NULL){
        mArray = mArray_longer;
        msize++;
        mArray[msize - 1] = x;
        return 1;
    } else {printf("realloc failed.\n"); return 0;}
}

bool Array::append(Array y){
    int more_elements = y.size();
    int* mArray_longer;
    if (msize == 0){
        mArray_longer = (int*)malloc(more_elements*sizeof(int));
    } else {
        mArray_longer = (int*)realloc(mArray, (msize + more_elements)*sizeof(int));
    }
    if(mArray_longer != NULL){
        int i;
        mArray = mArray_longer; //working
        int start = msize; // subtract because of 0 indexing
        msize = msize + more_elements;
        for (i = 0; i < more_elements; i++) {
            mArray[start + i] = y.mArray[i];
        }
        return 1;
    } else {printf("realloc failed.\n"); return 0;}
}

void Array::print(){
    if (msize > 0){
        int i;
        printf("printing array: \n");
        for (i = 0; i < msize; i++){
            printf("%d ", mArray[i]);
        }
        printf("\n");
    }
}

// Array operations go here 

Array& Array::operator=(Array other){ // need a copy constuctor and to pass reference 
    // cleanup(); // this causes problems if initialize hasn't been run 
    int i;
    int size = other.size();
    free(mArray);
    mArray = (int*)calloc(size, sizeof(int)); 
    if (mArray != NULL){
        msize = size;
        for (i = 0; i < msize; i++){
            mArray[i] = other.mArray[i];
        }
    }
    return *this;
}

int& Array::operator[](const int index){
    if (index >= 0 && index < msize){
        return mArray[index];
    } else {
        printf("error: index out of bounds.\n");
        exit(0);
    }
}

Array Array::operator+(Array& other){
    Array cat_array;
    cat_array.append(*this);
    cat_array.append(other);
    return cat_array;
}

std::ostream& operator<<(std::ostream& op, const Array& print) {
    if (print.msize > 0){
        op << "[";
        for (int i = 0; i < print.msize; i++){
            if(i != 0){op << ", ";}
            op << print.mArray[i];
        }
        op << "]";
    }
    return op;
}