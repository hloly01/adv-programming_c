#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <cstdio>
#include <bits/stdc++.h>

std::mutex mtx;

template <typename T>
class PriorityQueue{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.
  public:
    // constructors and destructors
    PriorityQueue(); // done
    PriorityQueue(PriorityQueue& copy); // copy constructor 
    ~PriorityQueue(); // done
    // operator overlaods 
    PriorityQueue& operator=(const PriorityQueue<T>& other); // create a deep copy here
    // array management 
    int size() const; // return size of priority queue 
    T top() const; // return largest value
    void push(T x); // add x to priority queue
    void pop(); // remove top item
    void print(); // done
    void reheap();

  private:
    std::vector<T> mHeap;
    int msize;
};

template <typename T> PriorityQueue<T>::PriorityQueue(){
  msize = 0;
  //mHeap = NULL;
  printf("default constructor called.\n");
}
template <typename T> PriorityQueue<T>::PriorityQueue(PriorityQueue& copy){
  printf("copy constructor called.\n");
  msize = copy.size();
  for (int i = 0; i < msize; i++){
    mHeap.push_back(copy.mHeap[i]);
  }
}

template <typename T> PriorityQueue<T>::~PriorityQueue(){
  mHeap.clear();
  mHeap.shrink_to_fit();
  msize = 0;
  printf("destructor called.\n");
}

template <typename T> int PriorityQueue<T>::size() const {return msize;}
template <typename T> T PriorityQueue<T>::top() const {return mHeap[0];}
template <typename T> void PriorityQueue<T>::reheap(){
  // find number of levels 
  int i;
  int offset;
  for (i = (msize - 1); i > 0; i--){ 
    offset = 1;
    if (i % 2 == 0){ // if number is even offset by 2
      offset = 2;
    }
    if (mHeap[i] > mHeap[(i-offset)/2]){ // if value greater than parent -> switch
      T temp = mHeap[(i-offset)/2];
      mHeap[(i-offset)/2] = mHeap[i];
      mHeap[i] = temp;
    }
  }
}

template <typename T> void PriorityQueue<T>::push(T x){
  std::lock_guard<std::mutex> lock(mtx);
  printf("locked in push.\n");
  mHeap.push_back(x);
  msize++;
  reheap();
}

template <typename T> void PriorityQueue<T>::pop(){
  std::lock_guard<std::mutex> lock(mtx);
  printf("locked in pop.\n");
  if (msize > 1){
    mHeap[0] = mHeap[msize - 1];
  }
  if (msize > 0){
    mHeap.pop_back();
    msize--;
  }
  reheap();
}

template <typename T> void PriorityQueue<T>::print(){
  printf("[");
  for (int i = 0; i < msize; i++){
    if (i != 0){printf(", ");}
    printf("%d", mHeap[i]);
  }
  printf("]\n");
}

template <typename T> PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other){  
  int i;
  msize = other.size();
  if(msize > 0){
    for (i = 0; i < msize; i++){
      mHeap.push_back(other.mHeap[i]);
    }
  }
  return *this;
}
#endif
