#include "include/climenuupdate.h"

void cli_menu_update_tail_update(List *list){
    printf("Write the new string of the tail: ");
    char input[BUFFERLEN];
    input_string(&input);
    update_tail(list, input);
}

void cli_menu_update_head_update(List *list){
    printf("Write the new string of the head: ");
    char input[BUFFERLEN];
    input_string(&input);
    update_head(list, input);
}

void cli_menu_update_index_update(List *list){
    printf("Type the desired index: ");
    char buffer[BUFFERLEN];
    input_string(&buffer);
    int number;
    if (sscanf(buffer, "%d", &number) == 1){
        printf("\nWrite the new string of %d node: ", number );
        char input[BUFFERLEN];
        input_string(&input);
        update_on_the_given_index(list, number, input);
    }else{
        printf("Invalid input!");
    }
}

void cli_menu_update_first_ocurrence_update(List *list){
    CLEAR;
    printf("Input The string to be replaced: ");
    char input[BUFFERLEN];
    input_string(&input);
    printf("Input the new string to be inserted: ");
    char strin[BUFFERLEN];
    input_string(&strin);
    update_first_ocurrence(list, strin, input);
}

void cli_menu_update_main(List *list){
    CLEAR;  
    printf("+=========================+\n");
    printf("|1 - Update tail          |\n");
    printf("|2 - Update head          |\n");
    printf("|3 - Update specifed index|\n");
    printf("|4 - Update specifed value|\n");
    printf("|0 - Cancel               |\n");
    printf("|(default update tail)    |\n");
    printf("+=========================+\n");
    printf("Input: ");
    char input[BUFFERLEN];
    input_string(&input);
    switch (input[0]) {
    case '1':
        cli_menu_update_tail_update(list);
        getchar();
        break;
    case '2':
        cli_menu_update_head_update(list);
        getchar();
        break;
    case '3':
        cli_menu_update_index_update(list);
        getchar();
        break;
    case '4':
        cli_menu_update_first_ocurrence_update(list);
        getchar();
        break;
    case '0':
        CLEAR;
        break;
    default:
        cli_menu_update_tail_update(list);
        getchar();
        break;
    }
}