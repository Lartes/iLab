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
    double cr;

    FILE *input=NULL, *output=NULL;
    if ((input=fopen("input.txt", "r"))==NULL)
        {printf("Cannot open file\n"); close;}
    if ((output=fopen("output.txt", "w"))==NULL)
        {printf("Cannot open file\n"); close;}

    while (fscanf(input,"%s",input_data_str)!=EOF){
        status=0;
        if (!stricmp(input_data_str,"push")){
            cr=PUSH;
            fwrite(&cr,sizeof(double),1,output);
            if (fscanf(input,"%lf",&input_data_doub)>0)
                fwrite(&input_data_doub,sizeof(double),1,output);
            else
                {printf("Incorrect command argument\n"); close;}
            status=1;
            *input_data_str='q';
        }
        if (!stricmp(input_data_str,"add")){
            cr=ADD;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"mul")){
            cr=MUL;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"pop_ax")){
            cr=POP_AX;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"push_ax")){
            cr=PUSH_AX;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"out")){
            cr=OUT;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"end")){
            cr=END;
            fwrite(&cr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"jmp")){
            cr=JMP;
            fwrite(&cr,sizeof(double),1,output);
            if (fscanf(input,"%lf",&input_data_doub)>0)
                fwrite(&input_data_doub,sizeof(double),1,output);
            else
                {printf("Incorrect command argument\n"); close;}
            status=1;
            *input_data_str='q';
        }
        if (!status) {printf("Incorrect command\n"); close;}

    }

    fclose(input);
    fclose(output);
    return 0;
}

