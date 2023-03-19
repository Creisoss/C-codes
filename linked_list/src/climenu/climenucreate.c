#include "include/climenucreate.h"

void cli_menu_add_to_the_list(List *list){
  if (is_empty(list)){
    printf("Write the first entry\n");
    Node *node = create_node();
    initialize_list(list, node);
  }else{
    printf("Write the new entry\n");
    Node *new_node = create_node();
    add_to_list(list, new_node);
    }
  CLEAR;
}

void cli_menu_add_to_the_head(List *list){
    if (is_empty(list)){
        printf("Write the first entry\n");
        Node *node = create_node();
        initialize_list(list, node);
    }else{  
        printf("Write the new entry\n");
        Node *new_node = create_node();
        add_new_header(list, new_node);
    }
    CLEAR;
}

void cli_menu_add_to_the_given_index(List *list){
    printf("Type the desired index: ");
    char buffer[BUFFERLEN];
    input_string(&buffer);
    int number;
    if (sscanf(buffer, "%d", &number) == 1){  
        printf("Write the new entry\n");
        Node *new_node = create_node();
        add_to_the_given_index(list, new_node,number);
    }else{
        printf("Invalid input!");
    }
}

void cli_menu_create_main(List *list){
    CLEAR;
    printf("+======================================+\n");
    printf("|1 - Add to the tail of the list       |\n");
    printf("|2 - Add to the given index on the list|\n");
    printf("|3 - Add to the head of the list       |\n");
    printf("|0 - Cancel                            |\n");
    printf("|(default add to the tail of the list) |\n");
    printf("+======================================+\n");
    printf("Input: ");
    char input[BUFFERLEN];
    input_string(&input);
    switch (input[0])
    {
    case '1':
        cli_menu_add_to_the_list(list);
        break;
    case '2':
        cli_menu_add_to_the_given_index(list);
        getchar();
        break;
    case '3':
        cli_menu_add_to_the_head(list);
        break;
    case '0':
        CLEAR;
        break;
    default:
        cli_menu_add_to_the_list(list);
        break;
    }
}