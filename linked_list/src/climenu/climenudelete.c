#include "include/climenudelete.h"

void cli_menu_delete_by_index(List *list){
  printf("Type the desired index: ");
  char buffer[BUFFERLEN];
  input_string(&buffer);
  int number;
  if (sscanf(buffer, "%d", &number) == 1){
    delete_on_index(list, number);
  }else{
    printf("Invalid input!");
  }
}

void cli_menu_delete_first_ocurrence(List *list){
  CLEAR;
  printf("Input The value to be deleted: ");
  char strin[BUFFERLEN];
  input_string(&strin);
  delete_first_ocurrence(list, strin);
}

void cli_menu_delete_main(List *list){
  CLEAR;
  printf("+=========================+\n");
  printf("|1 - Delete tail          |\n");
  printf("|2 - Delete head          |\n");
  printf("|3 - Delete specifed index|\n");
  printf("|4 - Delete specifed value|\n");
  printf("|0 - Cancel               |\n");
  printf("|(default deletes tail)   |\n");
  printf("+=========================+\n");
  printf("Input: ");
  char input[BUFFERLEN];
  input_string(&input);
  switch (input[0]) {
    case '1':
      pop(list);
      getchar();
      break;
    case '2':
      pop_head(list);
      getchar();
      break;
    case '3':
      cli_menu_delete_by_index(list);
      getchar();
      break;
    case '4':
      cli_menu_delete_first_ocurrence(list);
      getchar();
      break;
    case '0':
      CLEAR;
      break;
    default:
      pop(list);   
      break;
    }
}

