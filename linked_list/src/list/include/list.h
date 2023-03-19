#include "../../utils/include/utils.h"
#pragma once

typedef struct Node {
  char str[BUFFERLEN];
  struct Node *next;
}Node;

typedef struct List {
  Node *head;
  Node *tail;
  int size;
}List;

// initialize_lista: Initializes an existing empty list by pointing to an existing node = O(1)
void initialize_list(List *list,Node *node);
// create_node: Gets input from the user and encapsulate the user input inside a node = O(1) 
Node* create_node();
// is_empty: Checks if the current number of nodes in the list is 0 = O(1)
bool is_empty(List *list);
// one_element_list: Checks if the current number of nodes in the list is 1 = O(1)
bool one_element_list(List *list);
// add_to_list: Adds a node to the tail of the list = O(N)
void add_to_list(List *list, Node *node);
// add_new_header: Adds a node to the heade of the list = O(1)
void add_new_header(List *list, Node *node);
// add_to_the_given_index: Adds a node to an exisitng index in the list = O(N)
void add_to_the_given_index(List *list, Node *node, int index);
// print_list: Prints the list from the head to the tail = O(N)
void print_list(List *list);
// print_given_index: Prints the item on the given index = O(N)
void print_given_index(List *list, int index);
// print_first_ocurrence: Prints the first ocurrence of the given input = O(N)
void print_first_ocurrence(List *list, char strin[BUFFERLEN]);
// update_tail: Given a string, if the list isn't empty it will change the str at the tail of the list = O(1)
void update_tail(List *list, char strin[BUFFERLEN]);
// update_head: Given a string, if the list isn't empty it will change the str at the head of the list = O(1)
void update_head(List *list, char strin[BUFFERLEN]);
// update_on_the_given_index: Given an index it will change the str at the node in the given index = O(N)
void update_on_the_given_index(List *list, int index, char strin[BUFFERLEN]);
// update_first_ocurrence: Given a string it will find it first ocurrence and update based on another string = O(N)
void update_first_ocurrence(List *list, char strin[BUFFERLEN], char search_string[BUFFERLEN]);
// pop: Deletes the last element of the list = O(N)
void pop(List *list);
// pop_head: Deletes the first element of the list = O(1)
void pop_head(List *list);
// delete_on_index: Deletes the element of the given index = O(N)
void delete_on_index(List *list, int index);
// delete_on_index: Deletes the first element to match the given input = O(N)
void delete_first_ocurrence(List *list, char strin[BUFFERLEN]);
