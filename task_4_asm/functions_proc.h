#ifndef function_procIlab
#define function_procIlab

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"stack.h"

enum{
    PUSH=1,
    ADD,
    MUL,
    OUT,
    END,
    JMP
};

int no_enough(char* s,int n); //output errors

int push(struct item **stack, type new_element);

int add(struct item **stack);

int mul(struct item **stack);

int out(struct item **stack);

double *jmp(double *input_data0, int pointer);

#endif
