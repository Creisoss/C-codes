#include "include/starter.h"

void start_application(){
  List *list =  malloc(sizeof(struct List));
  list->size = 0;
  while (true){
    main_cli(list);
  }
  free(list);
}