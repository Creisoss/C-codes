#include "include/climenumain.h"

void main_cli(List *list){
  CLEAR;
  printf("+================+\n");
  printf("|1 - Create      |\n");
  printf("|2 - Read        |\n");
  printf("|3 - Update      |\n");
  printf("|4 - Delete      |\n");
  printf("|5 - File handler|\n");
  printf("|0 - Exit        |\n");
  printf("+================+\n");
  printf("Input: ");
  char input[BUFFERLEN];
  input_string(&input);
  switch (input[0]) {
    case '1':
      cli_menu_create_main(list);
      break;
    case '2':
      cli_menu_print_main(list);
      break;
    case '3':
      cli_menu_update_main(list);
      break;
    case '4':
      cli_menu_delete_main(list);
      break;
    case 5:
      cli_menu_file_handler(list);
      break;
    case '0':
      printf("Thanks\n");
      exit(0);
      break;
    default:
      CLEAR;
      printf("INVALID OPTION!!!\n");
      break;
    }
}