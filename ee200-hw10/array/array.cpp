#include "array.h"

int& Array::operator[](const int index){
    if (index >= 0 && index < msize){
        return mArray[index];
    } else {
        printf("error: index out of bounds.\n");
        exit(0);
    }
}

bool Array::initialize(int size, int value){
    int i;
    if (size >=0){
        mArray = (int*)calloc(size, sizeof(int)); 
        if (mArray == NULL){return 0;}
        msize = size;
        if (size > 0){
            for (i = 0; i < msize; i++) {
                mArray[i] = value;
            }
        }
        return 1;    
    } else {return 0;}
}

int Array::size(){return msize;} // return current size of array
void Array::cleanup(){free(mArray);}
bool Array::append(const int x){
    int i;
    int* mArray_longer = (int*)realloc(mArray, msize*sizeof(int) + sizeof(int));
    if(mArray_longer != NULL){
        mArray = mArray_longer;
        msize++;
        mArray[msize - 1] = x;
        printf("appended %d to mArray. mArray[%d] = %d\n", x, msize - 1, mArray[msize - 1]);
        return 1;
    } else {printf("realloc failed.\n"); return 0;}
}

bool Array::append(Array y){
    int more_elements = y.size();
    printf("allocate %d more elements.\n", y.size());
    int* mArray_longer = (int*)realloc(mArray, (msize + more_elements)*sizeof(int)); //working
    if(mArray_longer != NULL){
        int i;
        mArray = mArray_longer; //working
        int start = msize; // subtract because of 0 indexing
        printf("start at %d\n", start);
        msize = msize + more_elements;
        printf("size adjusted to %d. now fill array.\n", msize);
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
Array& Array::operator=(Array other){
    cleanup(); // this causes problems if initialize hasn't been run 
    int i;
    int size = other.size();
    mArray = (int*)calloc(size, sizeof(int)); 
    if (mArray != NULL){
        msize = size;
        for (i = 0; i < msize; i++){
            mArray[i] = other.mArray[i];
        }
    }
    return *this;
}
