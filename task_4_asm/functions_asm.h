#ifndef functions_asmIlab
#define functions_asmIlab

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int isNumF(char *s);

int isNum(char *s);

void close(FILE* input, FILE* output); //close ASM program after error

void closeD(FILE* input, FILE* output); //close DISASM program after error

int stricmp(const char *s1, const char *s2); //compare strings without register

#endif
