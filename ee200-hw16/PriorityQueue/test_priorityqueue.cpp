#include "priorityqueue.h"
#include <cstdio>
#include <thread>
#include <memory>


void print_hello(int i, PriorityQueue<int>& q){
  q.push(i);
  printf("Hello from thread %d. The current top of thread is %d\n", i, q.top());
}

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.
  int i;
  PriorityQueue<int> q;

  // Push three elements onto the front
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  printf("size of queue is %d\n", q.size());
  q.print();
  printf("top of priority queue is: %d\n", q.top());

  // Make a copy
  PriorityQueue<int> another(q);
  q.pop();
  printf("size of queue is %d\n", another.size());
  another.print();
  q.print();
  
  PriorityQueue<int> another_copy = q;

  // Push some more elements onto the front of the original
  q.push(4);
  q.push(5);

  while(q.size() > 0){
    printf("%d ", q.top());
    q.pop();
  }
  printf("\nprint q: \n");
  q.print();
  printf("\n");

  while(another_copy.size() > 0){
    printf("%d ", another_copy.top());
    another_copy.pop();
  }
  printf("\nprint another_copy (size %d): \n", another_copy.size());
  another_copy.print();
  printf("\n");

  // now add values back
  int new_values[] = {50,1,75,9,3,8,2,84,12,99,11,67,105,4};
  for (i = 0; i < 14; i++){
    another_copy.push(new_values[i]);
    another_copy.print();
  }
  printf("size of another_copy is %d\n", another_copy.size());

  // test that the class is thread safe

  PriorityQueue<int> thread_test;
  const int ten_threads = 10;
  std::thread threads[ten_threads];

  for (int i = 0; i < ten_threads; ++i) {
    threads[i] = std::thread(print_hello, i, std::ref(thread_test));
  }

  for (int i = 0; i < ten_threads; ++i) {
    threads[i].join();
  }
  
  return 0;
}

