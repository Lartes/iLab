#ifndef _RPN_H_
#define _RPN_H_

#include <stdio.h>
#include <stdlib.h>

enum{
    EXIT,
    INCORRECT_SYMBOL,
    NUMBER,
    PLUS,
    MINUS,
    MULT,
    DIV,
    ERROR
};

void read(char *s); //read a group of characters

int what_is_input(char *s); //recognition type of the read group

#endif
