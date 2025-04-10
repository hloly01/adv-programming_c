#include "linkedlist.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  LinkedList<int> list;
  printf(" list has %d items\n", list.size());

  // Push three elements onto the front
  list.insert(1, 0);
  list.insert(2, 0);
  list.insert(3, 0);

  // Make a copy
  LinkedList<int> another = list;

  // Push some more elements onto the front of the original
  list.insert(4, 0);
  list.insert(5, 0);
  list.insert(0, list.size());
  list.insert(-2, list.size());
  list.insert(-3, list.size());
  list.insert(-1, 6);

  int i;
  for(i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }
  printf(" list has %d items\n", list.size());

  list.remove(5);
  
  printf(" list has %d items\n", list.size());
  for(i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }
  
  list.remove(1);
  list.remove(0);
  
  printf("removed first item. list has %d items\n", list.size());
  for(i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }

  printf("getting and removing invalid item.\n");
  list.remove(190);
  list.remove(-10);
  list.getItem(190);
  list.getItem(-10);

  printf("another has %d items\n", another.size());
  for(int i = 0; i < another.size(); i++){
    printf("another[%d] = %d\n", i, another.getItem(i));
  }

  // testing floats and doubles
  double test_array[] = {1, 3, 5, 8, 9, 11, 14, 17, 19};
  printf("make a linked list with array: ");
  for (i = 0; i < 9; i++){
    printf("%lf ", test_array[i]);
  }
  printf("\n");

  LinkedList<double> list_init(9, test_array);
  LinkedList<double> list_cc(list_init);
  list_cc.insert(6,0);

  for(i = 0; i < list_init.size(); i++){
    printf(" list_init[%d] = %.2lf\n", i, list_init.getItem(i));
  }
  printf(" list_init has %d items\n", list_init.size());

  for(i = 0; i < list_cc.size(); i++){
    printf(" list_cc[%d] = %.2lf\n", i, list_cc.getItem(i));
  }
  printf("list_cc has %d items\n", list_cc.size());

  // testing chars
  char char_test[] = {'a', 'b', 'c', 'x', 'y', 'z'};

  LinkedList<char> testing(6, char_test);
  testing.insert('d', 3);
  testing.insert('w', 4);
  for(i = 0; i < testing.size(); i++){
    printf(" testing[%d] = %c\n", i, testing.getItem(i));
  }
  printf("testing has %d items\n", testing.size());

  // fail testing
  LinkedList<int> fail_1(10, NULL);
  LinkedList<char> fail_2(-10, char_test);

  printf("testing self assignment.\n");
  testing = testing;
  for(i = 0; i < testing.size(); i++){
    printf(" testing[%d] = %c\n", i, testing.getItem(i));
  }
  printf("testing has %d items\n", testing.size());

  return(0);
}

