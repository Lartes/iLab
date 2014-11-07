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
    POP_AX,
    PUSH_AX,
    POP_BX,
    PUSH_BX,
    OUT,
    END,
    JMP,
    JZ,
    JNZ,
    CMP
};

int no_enough(char* s,int n); //output errors

int push(struct item **stack, type new_element);

int add(struct item **stack);

int mul(struct item **stack);

int popReg(struct item **stack,type *reg);

int pushReg(struct item **stack,type reg);

int out(struct item **stack, char output_name[20]);

double *jmp(double *input_data0, int pointer);

double *jz(struct item **stack, double *input_data0, double *input_data, int pointer);

double *jnz(struct item **stack, double *input_data0, double *input_data, int pointer);

int cmp(struct item **stack);

#endif
