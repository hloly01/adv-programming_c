#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>


template <typename T>
class LinkedList{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
 
  public:
    // constructors and destructors
    LinkedList(); // done
    LinkedList(int length, T* values); // done
    LinkedList(LinkedList& copy); // copy constructor (not done)
    ~LinkedList(); // done
    // operator overlaods 
    LinkedList& operator=(const LinkedList<T>& other); // create a deep copy here (not done)
    // array management 
    int size() const; // return number of elements in array (done)
    T getItem(int index); // return item (done)
    bool remove(int pos); // done
    bool insert(T x, int pos); // insert x at position pos (done)

  private:
    struct Item{
      Item* next;
      T value;
    };
    Item* mHead;
    int msize;
};


// Constructors + destructor go here

template <typename T> LinkedList<T>::LinkedList(){ // no exceptions
  msize = 0;
  mHead = NULL;
  printf("default constructor called.\n");
}

template <typename T> LinkedList<T>::LinkedList(int length, T* values){ // working
    printf("LinkedList(int length, T* values) constructor called.\n");
    int i;
    mHead = NULL;
    msize = 0;
    if (values != NULL){
      if (length >=0){
        if (length > 0){
          Item* nextup = mHead;
          for (i = 0; i < length; i++) {
            Item* new_item = new Item;
            if (i == 0){
              mHead = new_item;
            } else {nextup->next = new_item;}
            new_item->value = values[i];
            new_item->next = NULL;
            nextup = new_item;
            msize++;
          }
        }   
      } else {
        printf("array length cannot be negative!\n");
      }
    } else {
      printf("cannot copy a NULL array.\n");
    }
}

template <typename T> LinkedList<T>::LinkedList(LinkedList& copy){ // working
    printf("copy constructor called.\n");
    int i;
    mHead = NULL;
    msize = 0;
    if (copy.size() > 0){
      Item* nextup = mHead;
      Item* next_copy = copy.mHead;
      for (i = 0; i < copy.size(); i++) {
        Item* new_item = new Item;
        if (i == 0){
          mHead = new_item;
        } else {nextup->next = new_item;}
        new_item->value = next_copy->value;
        new_item->next = NULL;
        nextup = new_item;
        next_copy = next_copy->next;
        msize++;
      }
    }   
}

template <typename T> LinkedList<T>::~LinkedList(){
    printf("destructor called.\n");
    Item* current = mHead;
    Item* next_item = NULL;
    while (current != NULL){
      next_item = current->next;
      delete current;
      current = next_item;
    }
    msize = 0;
}

// Array operations go here 

template <typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
  if (other.mHead != mHead){
    int i;
    mHead = NULL;
    msize = 0;
    if (other.size() > 0){
      Item* nextup = mHead;
      Item* next_copy = other.mHead;
      for (i = 0; i < other.size(); i++) {
        Item* new_item = new Item;
        if (i == 0){
          mHead = new_item;
        } else {nextup->next = new_item;}
        new_item->value = next_copy->value;
        new_item->next = NULL;
        nextup = new_item;
        next_copy = next_copy->next;
        msize++;
      }
    }  
  }
  return *this;
}
// Array management goes here

template <typename T> int LinkedList<T>::size() const {return msize;} // return current size of array
template <typename T> bool LinkedList<T>::remove(int pos) { // working
  if (pos >= 0 && pos <= size()){
    Item* nextup = mHead;
    int i;
    if (pos == 0){
      Item* temp = NULL;
      temp = mHead->next;
      delete mHead;
      mHead = temp;
      msize--;
      return 0;
    }
    for (i = 0; i < pos; i++){
      if (i == pos - 1){
        Item* temp = NULL;
        if (nextup->next != NULL){
          temp = nextup->next->next;
        }
        delete nextup->next;
        nextup->next = temp;
        msize--;
        return 0;
      }
      nextup = nextup->next;
    }    
  } else {printf("invalid remove.\n");}
  return 0;
}

template <typename T> T LinkedList<T>::getItem(int pos) { // working
  if (pos >= 0 && pos <= size()){
    int i;
    Item* nextup = mHead;
    for (i = 0; i <= pos; i++){
      if (i == pos){return nextup->value;}
      nextup = nextup->next;
    }
  } else {printf("invalid getItem()\n");}
  return mHead->value;
}

template <typename T> bool LinkedList<T>::insert(T x, int pos){ // working
    int i;
    if (mHead == NULL && pos != 0){
      printf("position does not exist\n");
      return 0;
    }
    if (pos != 0){
      Item* nextup = mHead;
      for (i = 0; i < pos; i++){
        if (i == pos-1){
          Item* new_item = new Item;
          new_item->next = nextup->next;
          nextup->next = new_item;
          new_item->value = x;
          msize++;
          return 0;
        }
        nextup = nextup->next;
      }
    } else {
      Item* new_item = new Item;
      if (mHead != NULL){
        new_item->next = mHead;
        mHead = new_item;
      } else {
        mHead = new_item;
        new_item->next = NULL;
      }
      new_item->value = x;
      msize++;
    }
    return 0;
}

#endif
