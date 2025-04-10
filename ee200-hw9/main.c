#include "mon.h"

int main(int argc, char* argv[])
{
  /* This code should create the tree below:
   *            aardvark
   *             /   \
   *        baboon   zebra
   *        /   \
   * xenops  yak
   */
  Element* a = create_element("aardvark");
  Element* b = create_left(a, "baboon");
  Element* x = create_left(b, "xenops");
  Element* y = create_right(b, "yak");
  Element* z = create_right(a, "zebra");

  //Element* c = create_left(z, "cheetah");
  //Element* d = create_right(z, "donkey");
  
  Element* null1 = create_element(NULL);
  Element* null2 = create_right(NULL, "yak");
  Element* null3 = create_right(b, NULL);
  assert(null1 == NULL);
  assert(null2 == NULL);
  assert(null3 == NULL);
  Element* g = create_left(a, "ghost_bat");
  assert(g == NULL);


  FILE* f = fopen("tree.mon", "w");
  write_tree(f, a);
  // // Clean up!
  fclose(f);
  free_tree(a);

  FILE* r = fopen("multilevel.mon", "r");
  if (r != NULL){
    Element* test = load_tree(r);
    FILE* write_new = fopen("tree_again.mon", "w");
    int multilevel = write_tree(write_new, test);
    assert(multilevel == 0);
    if (test==NULL){printf("problem.\n");}
    free_tree(test);
    fclose(write_new);
    fclose(r);
  }

  FILE* r1 = fopen("sample1.mon", "r");
  if (r1 != NULL) {
    Element* test1 = load_tree(r1);
    assert(test1 == NULL);
    free_tree(test1);
    fclose(r1);
  }

  FILE* r2 = fopen("sample2.mon", "r");
  if (r2 != NULL) {
    Element* test2 = load_tree(r2);
    assert(test2 == NULL);
    fclose(r2);
  }

  FILE* r3 = fopen("sample3.mon", "r");
  if (r3 != NULL) {
    Element* test3 = load_tree(r3);
    assert(test3 == NULL);
    fclose(r3);
  }
  FILE* r4 = fopen("sample4.mon", "r");
  if (r4 != NULL) {
    Element* test4 = load_tree(r4);
    assert(test4 == NULL);
    fclose(r4);
  }
  FILE* r5 = fopen("sample5.mon", "r");
  if (r5 != NULL) {
    Element* test5 = load_tree(r5);
    assert(test5 == NULL);
    fclose(r5);
  }

  FILE* r6 = fopen("sample6.mon", "r");
  if (r6 != NULL) {
    Element* test6 = load_tree(r6);
    assert(test6 == NULL);
    fclose(r6);
  }

  Element* null4 = load_tree(NULL);
  assert(null4 == NULL);
  write_tree(NULL, null4);
}

