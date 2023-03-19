#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H
#define CLEAR printf("\e[1;1H\e[2J")
#define BUFFERLEN 256
#endif

// input_string: A general input string function
void input_string(char (*input)[BUFFERLEN]);