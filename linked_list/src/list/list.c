#include "./include/list.h"

void initialize_list(List *list, Node *node) {
  list->head = node;
  list->tail = node;
  list->size = 1;
}

Node* create_node(){
  char buf[BUFFERLEN];
  printf("Input: ");
  fgets(buf, BUFFERLEN, stdin);
  Node *new_node = (Node*) malloc(sizeof(Node));
  memcpy(new_node->str, buf, BUFFERLEN);
  new_node->next = NULL;
  return new_node;
}

bool is_empty(List *list){
  return list->size == 0;
}

bool one_element_list(List *list){
  return list->size == 1;
}

void add_to_list(List *list, Node *node){
  list->tail->next = node;
  list->tail = node;
  list->size++;
}

void add_new_header(List *list, Node *node){
  node->next = list->head;
  list->head = node;
  list->size++;
}

void add_to_the_given_index(List *list, Node *node, int index){
  if(is_empty(list)){
    printf("The list is empty!, the node will be added to the head\n");
    initialize_list(list, node);
    return;
  }else if(index >= list->size){
    printf("The index is bigger than the size of the list so the node will be added to the tail\n");
    add_to_list(list, node);
    return;
  }else if(index <= 0){
    printf("The index is lower or equal to 0 so the node will be added to the head of the list\n");
    add_new_header(list, node);
    return;
  }else{
    Node *rom_node = list->head;
    for(int i = 0; i <= index; i++){
      if (i == index - 1){
        list->size++;
        node->next = rom_node->next;
        rom_node->next = node;
        return;
      }
      rom_node = rom_node->next;
    }
  }
}

void print_list(List *list){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  } 
  Node *node = list->head;
  for(int i = 0; i < list->size; i++){
    printf("%d -> %s", i ,node->str);
    node = node->next;
  }
}

void print_given_index(List *list, int index){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }else if((index > list->size - 1) || (index < 0)){
    printf("Index out of range");
    return;
  }else{
    Node *node = list->head;        
    for(int i = 0; i <= index; i++){
      if(i == index){
        printf("%d - %s\n", index, node->str);
        return;
      }
      node = node->next;
    }
  }
  
}

void print_first_ocurrence(List *list, char strin[BUFFERLEN]){
  if (is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  Node *node = list->head;
  for(int i = 0; i < list->size; i++){
    if(strcmp(node->str, strin) == 0){
      printf("%d - %s\n", i, node->str);
      return;
    }
    node = node->next;
  }
  printf("Not found!");
}

void update_tail(List *list, char strin[BUFFERLEN]){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  memcpy(list->tail->str, strin, BUFFERLEN);
}

void update_head(List *list, char strin[BUFFERLEN]){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  memcpy(list->head->str, strin, BUFFERLEN);
}

void update_on_the_given_index(List *list, int index, char strin[BUFFERLEN]){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }else if(index < 0 || index > list->size - 1){
    printf("Index out of range!!");
    return;
  }
  Node *node = list->head;
  for (int i = 0; i <= index; i++){
    if(i == index){
      memcpy(node->str, strin, BUFFERLEN);
      return;
    }
    node = node->next;
  }
}

void update_first_ocurrence(List *list, char strin[BUFFERLEN], char search_string[BUFFERLEN]){
  if(is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  Node *node = list->head;
  for(int i = 0; i < list->size; i++){
    if(strcmp(node->str, search_string) == 0){
      memcpy(node->str, strin, BUFFERLEN);
      return;
    }
    node = node->next;
  }
  printf("Not found!!");
}

void pop(List *list){
  if (is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }else if (one_element_list(list)) {
    list->size = 0;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
  }else {
    list->size--;
    Node *node = list->head;
    for(int i = 0; i < list->size; i++){
      if (node->next == list->tail){
        free(list->tail);
        list->tail = node;
        return;
      }else {
        node = node->next;
      }
    }
  }
}

void pop_head(List *list){
  if (is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  list->size--;
  Node *old_head = list->head;
  list->head = old_head->next;
  free(old_head);

}

void delete_on_index(List *list, int index){
  if(is_empty(list)) {
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  if((index  > list->size - 1) || (index < 0)) {
    printf("Index out of range\n");
    return;
  }
  if(one_element_list(list) || index == 0){
    pop_head(list);
    return;
  }
  if(index == list->size - 1){
    pop(list);
    return;
  }
  Node *node = list->head;
  for(int i = 0; i <= index; i++){
    if(i == index-1){
      Node *point_to_deleted_value = node->next;
      node->next = node->next->next;
      free(point_to_deleted_value);
      list->size--;
      return;
    }
    node = node->next;
  }
} 

void delete_first_ocurrence(List *list, char strin[BUFFERLEN]){
  if(is_empty(list)) {
    printf("THE LIST IS EMPTY!!!\n");
    return;
  }
  Node *node = list->head;
  for(int i = 0; i < list->size; i++){
    if(strcmp(node->str, strin) == 0){
      delete_on_index(list, i);
      return;
    }else{
      node = node->next;
    }
  }
  printf("Not found!");
  return;
}