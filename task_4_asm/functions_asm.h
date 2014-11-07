#ifndef functions_asmIlab
#define functions_asmIlab

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>

struct label{
    char name[10];
    int addres;
};

int isNumF(char *s);

int isNum(char *s);

void close(FILE* input, FILE* output, char output_name[20]); //close program after error

int stricmp(const char *s1, const char *s2); //compare strings without register

int addres_label(struct label *mas_label, int size, char input_data_str[10]); //return addres of label's object

char* label_addres(struct label *mas_label, int size, int addres); //return label according to addres

int jumpASM(FILE* input, FILE* output, struct label *mas_label, int size); //reading and writing addres of jump; if jump successful, return 1, else reurn 0

int jumpDISASM(FILE* input, FILE* output, struct label *mas_label, int size);  //reading and writing addres of jump; if jump successful, return 1, else reurn 0

#endif
