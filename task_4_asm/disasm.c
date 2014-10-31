#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"
#include"functions_asm.h"

#define closeD closeD(input,output)

int main(){
    double input_data;
    int status;

    FILE *input=NULL, *output=NULL;
    if ((output=fopen("input.txt", "w"))==NULL)
        {printf("Cannot open file"); closeD;}
    if ((input=fopen("output.txt", "r"))==NULL)
        {printf("Cannot open file"); closeD;}

    while (fscanf(input,"%lf",&input_data)!=EOF){
        status=0;
        if (input_data==PUSH){
            fprintf(output,"push ");
            if (fscanf(input,"%lf",&input_data)>0)
                fprintf(output,"%lf\n",input_data);
            else
                {printf("Incorrect command argument\n"); closeD;}
            status=1;
        }
        if (input_data==ADD){
            fprintf(output,"add\n");
            status=1;
        }
        if (input_data==MUL){
            fprintf(output,"mul\n");
            status=1;
        }
        if (input_data==OUT){
            fprintf(output,"out\n");
            status=1;
        }
        if (input_data==END){
            fprintf(output,"end\n");
            status=1;
        }
        if (input_data==JMP){
            fprintf(output,"jmp ");
            if (fscanf(input,"%lf",&input_data)>0)
                fprintf(output,"%lf\n",input_data);
            else
                {printf("Incorrect command argument\n"); closeD;}
            status=1;
        }
        if (!status) {printf("Incorrect command"); closeD;}

    }

    fclose(input);
    fclose(output);
}

