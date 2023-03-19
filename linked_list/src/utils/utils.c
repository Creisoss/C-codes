#include "include/utils.h"

// This odd implementation was made so there was no warnings during compilation
void input_string(char (*input)[256]){
    char s[BUFFERLEN];
    fgets(s, BUFFERLEN, stdin);
    memcpy(input, s, BUFFERLEN);
}