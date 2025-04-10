#include <cstdio>
#include <assert.h>
#include "btree.h"

int main(int argc, char* argv[])
{
  int i;
  BTree basics;
  int new_values[] = {26,6,44,35,24,72}; //,11,67,105,4};
  for (i = 0; i < 6; i++){
    basics.add(new_values[i]);
    assert(basics.contains(new_values[i]));
  }
  int new_values_sorted[] = {6,24,26,35,44,72};
  int* check_order = basics.toArray();
  for (i = 0; i < 6; i++){
    assert(new_values_sorted[i] == check_order[i]);
  }

  BTree copy_con(basics);
  int* copy_con_array = copy_con.toArray();
  for (i = 0; i < 6; i++){
    assert(check_order[i] == copy_con_array[i]);
  }
  printf("copy constructor worked.\n");
  basics.remove(44);
  assert(basics.contains(44) == 0);
  assert(copy_con.contains(44));

  printf("this test passed.\n");
  return 0;
}

