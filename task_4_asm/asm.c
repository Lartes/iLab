#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"
#include"functions_asm.h"

#define close close(input,output)

int main(){
    double input_data_doub;
    char input_data_str[10];
    int status;

    FILE *input=NULL, *output=NULL;
    if ((input=fopen("input.txt", "r"))==NULL)
        {printf("Cannot open file"); close;}
    if ((output=fopen("output.txt", "w"))==NULL)
        {printf("Cannot open file"); close;}

    while (fscanf(input,"%s",input_data_str)!=EOF){
        status=0;
        if (!stricmp(input_data_str,"push")){
            fprintf(output,"%d ",PUSH);
            if (fscanf(input,"%lf",&input_data_doub)>0)
                fprintf(output,"%lf\n",input_data_doub);
            else
                {printf("Incorrect command argument\n"); close;}
            status=1;
        }
        if (!stricmp(input_data_str,"add")){
            fprintf(output,"%d\n",ADD);
            status=1;
        }
        if (!stricmp(input_data_str,"mul")){
            fprintf(output,"%d\n",MUL);
            status=1;
        }
        if (!stricmp(input_data_str,"out")){
            fprintf(output,"%d\n",OUT);
            status=1;
        }
        if (!stricmp(input_data_str,"end")){
            fprintf(output,"%d\n",END);
            status=1;
        }
        if (!stricmp(input_data_str,"jmp")){
            fprintf(output,"%d ",JMP);
            if (fscanf(input,"%lf",&input_data_doub)>0)
                fprintf(output,"%lf\n",input_data_doub);
            else
                {printf("Incorrect command argument\n"); close;}
            status=1;
        }
        if (!status) {printf("Incorrect command"); close;}

    }

    fclose(input);
    fclose(output);
}

