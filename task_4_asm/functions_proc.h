#ifndef function_procIlab
#define function_procIlab

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include"stack.h"

enum{
    PUSH=1,
    ADD,
    SUB,
    MUL,
    DIV,
    SQRT,
    POP_AX,
    PUSH_AX,
    POP_BX,
    PUSH_BX,
    POP_CX,
    PUSH_CX,
    POP_DX,
    PUSH_DX,
    OUT,
    END,
    JMP,
    JZ,
    JNZ,
    JE,
    JL,
    JG,
    CMP,
    CALL,
    RET
};

void stop(FILE* input, char output_name[20], double *input_data, double *input_data0, struct item **stack,  struct item **stack_func);

int no_enough(char* s,int n); //output errors

int push(struct item **stack, type new_element);

int add(struct item **stack);

int sub(struct item **stack);

int mul(struct item **stack);

int div_my(struct item **stack);

int sqrt_my(struct item **stack);

int popReg(struct item **stack,type *reg);

int pushReg(struct item **stack,type reg);

int out(struct item **stack, char output_name[20]);

double *jmp(double *input_data0, int pointer);

double *jz(struct item **stack, double *input_data0, double *input_data, int pointer);

double *jnz(struct item **stack, double *input_data0, double *input_data, int pointer);

double *je(struct item **stack, double *input_data0, double *input_data, int pointer);

double *jl(struct item **stack, double *input_data0, double *input_data, int pointer);

double *jg(struct item **stack, double *input_data0, double *input_data, int pointer);

int cmp(struct item **stack);

double *ret(struct item **stack, double *input_data0);

#endif
