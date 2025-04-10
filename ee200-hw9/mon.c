#include "mon.h"
#define _GNU_SOURCE

Element* create_element(char* data)
{
  if (data != NULL) {
    struct element_t *pointer = malloc(sizeof(struct element_t));
    if(pointer != NULL){
      pointer->name = (char*)malloc((sizeof(char)*strlen(data)) + 1);
      if (pointer->name != NULL){
        strcpy(pointer->name, data);
      } //else {return NULL;} // couldn't get this to fail 
      pointer->left_child = NULL;
      pointer->right_child = NULL;
    }
    return pointer;
  }
  return NULL;
}

Element* create_left(Element* root, char* data)
{
  if (data != NULL && root != NULL) {
    if (root->left_child == NULL) {
      Element* pointer = create_element(data);
      root->left_child = pointer;
      return pointer;
    }
  }
  return NULL;
}

Element* create_right(Element* root, char* data)
{
  if (data != NULL && root != NULL) {
    if (root->right_child == NULL) {
      Element* pointer = create_element(data);
      root->right_child = pointer;
      return pointer;
    }
  }
  return NULL;
}

void free_tree(Element* root)
{
  if(root != NULL){
    free_tree(root->left_child);
    free_tree(root->right_child);
    free(root->name);
    free(root);
  }
}

int write_tree(FILE* f, Element* e)
{
  if (f != NULL){
    if (e != NULL){
      fprintf(f, "{");
      if (e->left_child != NULL) {
        write_tree(f, e->left_child);
      } else {fprintf(f, "NULL ");}
      if (e->right_child != NULL) {
        write_tree(f, e->right_child);
      } else {fprintf(f, "NULL ");}
      fprintf(f, "%s}", e->name);
      return 0;
    }
  }
  return -1;
}

void get_name(const char mon[], int start, char name[], char side, Element* root) {
  int i;
  char bw_root[200] = ""; 
  for((i = start); i >= 0; i--){
    if (mon[i] == 32 || mon[i] == 125) {break;}
    bw_root[start - i] = mon[i]; // counts up from zero
  }
  // reverse it
  for(i = 0; i <= strlen(bw_root); i++){
    name[i] = bw_root[strlen(bw_root) - 1 - i]; // subtract one to skip NULL
  }
  if (root != NULL) {
    switch(side) {
    case 'l':
      create_left(root, name);
      break;
    case 'r':
      create_right(root, name); 
      break;
    }
  }
}

int get_child(const char mon[], int start, Element* root, char side, Element** ptr){
  if (start < 0){
    return -2;
  }
  if (mon[start] == '}') {
    start = get_tree(mon, start, root, side, ptr);
  } else if (mon[start] == ' '){
    start = start - 5;
  } else {
    return -2;
  }
  return start;
}

int get_tree(const char mon[], int start, Element* root, char side, Element** ptr){
  if (start < 0){ return -1;}
  char recursion_name[200] = "";
  get_name(mon, start - 1, recursion_name, side, root);
  // set whatever you just made as new root
  if (root == NULL){
    root = create_element(recursion_name);
    if (*ptr == NULL){
      *ptr = root;
      }
  } else if (side == 'l'){root = root->left_child;
  } else if (side == 'r'){root = root->right_child;}
  side = 'r';  // establish new roots right side
  start = start - 1 - strlen(recursion_name);
  start = get_child(mon, start, root, side, ptr);
  // done getting right child, get left child
  side = 'l';
  start = get_child(mon, start, root, side, ptr);
  if (start < 0){ return -2;
  } else if (mon[start] != '{'){return -2;}
  return (start - 1);
}
int check_start(const char mon[], int start){
  if (mon[start] != '}'){
    if(mon[start] == ' ' || mon[start] == '\n'){
      start--;
      check_start(mon, start);
    } else {
      return -1;
    } 
  } else {
    return start;}
}
Element* load_tree(FILE* f){
  if (f != NULL){
    char * line = NULL;
    size_t len = 0;
    size_t read;
    int index;
    read = getline(&line, &len, f);
    index = read - 1;
    // implement something to skip new lines and spaces until we hit a '}'. 
    // if it isnt a new line, space or } then file is corrupt 
    index = check_start(line, index);
    if (index < 0){
      free(line);
      return NULL;
    }
    Element* new_tree = NULL; //tree that gets built
    Element* pointer = NULL; // static pointer to the tree
    int check = get_tree(line, index, new_tree, 'r', &pointer);
    if (check == -2){
      free_tree(pointer);
      free(line);
      return NULL;}
    free(line);
    return pointer;
  } else {
    return NULL;
  }
}
