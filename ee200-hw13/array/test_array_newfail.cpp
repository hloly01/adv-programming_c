// Implement a version of `new` that fails on command
// Based on https://stackoverflow.com/questions/1923664/simulating-low-memory-using-c
#include <cstdlib>
#include <iostream>

// Global flag that sets whether or not `new` will fail
bool memoryAllocFail = false; // Succeed by default

// Custom implementation of new
void* operator new(std::size_t size)
{
    std::cout << "New allocation of size " << size << std::endl;
    if (memoryAllocFail){
       throw std::bad_alloc();
    }

    return malloc(size);
}

void operator delete(void* block){
    std::cout << "Freed allocation" << std::endl;
    free(block);
}

int main(int argc, char* argv[])
{
    printf("allocate memory normally.\n");
    int* a = new int[10];
    delete[] a;

    printf("turn on auto new fail.\n");

    memoryAllocFail = true;

    try {
        printf("throwing exception now.\n");
        int* b = new int[10];
        delete[] b;
    }
    catch (std::exception e) {
        std::cout << "oh, that didn't go well" << std::endl;
    }

    return(0);
}

