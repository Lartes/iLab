#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"
#include"functions_asm.h"

#define closeD closeD(input,output) //исправить двойное печатанье команды после

int main(){
    double input_data_d;
    double input_data;
    int status;

    FILE *input=NULL, *output=NULL;
    if ((output=fopen("input.txt", "w"))==NULL)
        {printf("Cannot open file\n"); closeD;}
    if ((input=fopen("output.txt", "r"))==NULL)
        {printf("Cannot open file\n"); closeD;}

    while (fread(&input_data,sizeof(double),1,input)>0){
        status=0;
        if (input_data==PUSH){
            fprintf(output,"push ");
            if (fread(&input_data_d,sizeof(double),1,input)>0)
                fprintf(output,"%lf\n",input_data_d);
            else
                {printf("Incorrect command argument\n"); closeD;}
            status=1;
            input_data=666;
        }
        if (input_data==ADD){
            fprintf(output,"add\n");
            status=1;
        }
        if (input_data==MUL){
            fprintf(output,"mul\n");
            status=1;
        }
        if (input_data==POP_AX){
            fprintf(output,"pop_ax\n");
            status=1;
        }
        if (input_data==PUSH_AX){
            fprintf(output,"push_ax\n");
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
            if (fread(&input_data_d,sizeof(double),1,input)>0)
                fprintf(output,"%lf\n",input_data_d);
            else
                {printf("Incorrect command argument\n"); closeD;}
            status=1;
            input_data=666;
        }
        if (!status) {printf("Incorrect command\n"); closeD;}

    }

    fclose(input);
    fclose(output);
    return 0;
}

