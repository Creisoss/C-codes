#include "include/climenuprint.h"

void cli_menu_print_the_list(List *list){
  if (is_empty(list)){
    printf("THE LIST IS EMPTY!!!\n");
  }else{
    CLEAR;
    print_list(list);
  }
}


void cli_menu_print_on_the_given_index(List *list){
    printf("Type the desired index: ");
    char buffer[BUFFERLEN];
    input_string(&buffer);
    int number;
    if (sscanf(buffer, "%d", &number) == 1){
        print_given_index(list, number);
    }else{
        printf("Invalid input!");
    }
}


void cli_menu_print_first_ocurrence(List *list){
    CLEAR;
    printf("Input The value to be printed: ");
    char strin[BUFFERLEN];
    input_string(&strin);
    print_first_ocurrence(list, strin);
}


void cli_menu_print_main(List *list){
    CLEAR;
    printf("+================================================+\n");
    printf("|1 - Print the entire List                       |\n");
    printf("|2 - Print the element on the given index        |\n");
    printf("|3 - Print the first ocurrence of the given input|\n");
    printf("|0 - Cancel                                      |\n");
    printf("|(default print the entire list)                 |\n");
    printf("+================================================+\n");
    printf("Input: ");
    char input[BUFFERLEN];
    input_string(&input);
    switch (input[0])
    {
    case '1':
        cli_menu_print_the_list(list);
        getchar();
        break;
    case '2':
        cli_menu_print_on_the_given_index(list);
        getchar();
        break;
    case '3':
        cli_menu_print_first_ocurrence(list);
        getchar();
        break;
    case '0':
        break;
    default:
        cli_menu_print_the_list(list);
        getchar();
        break;
    }
    CLEAR;
}