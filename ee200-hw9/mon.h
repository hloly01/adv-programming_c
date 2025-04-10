/* mon.h
 * Library of functions for "Minimal object notation" (MON). */

#ifndef MON_H
#define MON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct element_t {
  char* name;
  struct element_t* left_child;
  struct element_t* right_child;
} Element;


Element* create_element(char* data);
Element* create_left(Element* root, char* data);
Element* create_right(Element* root, char* data);

void free_tree(Element* root);
void print_tree(Element* root);
void get_name(const char mon[], int start, char name[], char side, Element* root);
int get_child(const char mon[], int start, Element* root, char side, Element** ptr);
int get_tree(const char mon[], int start, Element* root, char side, Element**);
int check_start(const char mon[], int start);
int write_tree(FILE*, Element* root);
Element* load_tree(FILE* f);

#endif

