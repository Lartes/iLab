#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"
#include"functions_asm.h"

#define close close(input,output,output_name,mas_label)

int main(int argv, char* argc[]){


    //initialization of variables
    double input_data;
    int status, i, size, addres=0;
    char input_name[20], output_name[20], sys[20];
    struct label *mas_label=(struct label*)calloc(1,sizeof(struct label));
    FILE *input=NULL, *output=NULL;


    //open input and output files
    if (argv==3){
        strcpy(input_name,argc[1]);        //from command line
        strcpy(output_name,argc[2]);
    }
    else{ if (argv==1){
             strcpy(input_name,"output.txt");  //default
             strcpy(output_name,"input.txt");
         }
         else {printf("Input names of file aren't full\n"); close;}
    }

    if ((output=fopen(output_name, "w"))==NULL)
        {printf("Cannot open file\n"); close;}


    //reading information about labels from file
    if (strchr(input_name,'.')!=NULL){  //create name of file
        strncpy(sys,input_name,strchr(input_name,'.')-input_name);
        sys[strchr(input_name,'.')-input_name]='\0';
    }
    else strcpy(sys,input_name);
    strcat(sys,"_sys.txt");

    if ((input=fopen(sys, "r"))==NULL)  //reading system file
        {printf("Cannot read system file\n"); close;}
    fscanf(input,"%d", &size);
    mas_label=(struct label*)realloc(mas_label,size*sizeof(struct label));
    for (i=0;i<=size-1;i++){
        fscanf(input,"%s %d", (mas_label[i]).name, &((mas_label[i]).addres));
    }
    fclose(input);


    //open input file
    if ((input=fopen(input_name, "r"))==NULL)
        {printf("Cannot open file\n"); close;}


    //reading
    while (fread(&input_data,sizeof(double),1,input)>0){
        status=0;
        if (strcmp(label_addres(mas_label,size,addres),"-1"))  //adding label if it exist
            fprintf(output,"%s:\n",label_addres(mas_label,size,addres));

        if (input_data==PUSH){
            fprintf(output,"push ");
            if (fread(&input_data,sizeof(double),1,input)>0){
                fprintf(output,"%lf\n",input_data);
                addres++;
            }
            else
                {printf("Incorrect command argument\n"); close;}
            status=1;
            input_data=666;
        }
        if (input_data==ADD){
            fprintf(output,"add\n");
            status=1;
        }
        if (input_data==SUB){
            fprintf(output,"sub\n");
            status=1;
        }
        if (input_data==MUL){
            fprintf(output,"mul\n");
            status=1;
        }
        if (input_data==DIV){
            fprintf(output,"div\n");
            status=1;
        }
        if (input_data==SQRT){
            fprintf(output,"sqrt\n");
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
        if (input_data==POP_BX){
            fprintf(output,"pop_bx\n");
            status=1;
        }
        if (input_data==PUSH_BX){
            fprintf(output,"push_bx\n");
            status=1;
        }
        if (input_data==POP_CX){
            fprintf(output,"pop_cx\n");
            status=1;
        }
        if (input_data==PUSH_CX){
            fprintf(output,"push_cx\n");
            status=1;
        }
        if (input_data==POP_DX){
            fprintf(output,"pop_dx\n");
            status=1;
        }
        if (input_data==PUSH_DX){
            fprintf(output,"push_dx\n");
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
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==JZ){
            fprintf(output,"jz ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==JNZ){
            fprintf(output,"jnz ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==JE){
            fprintf(output,"je ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==JL){
            fprintf(output,"jl ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==JG){
            fprintf(output,"jg ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==CMP){
            fprintf(output,"cmp\n");
            status=1;
        }
        if (input_data==CALL){
            fprintf(output,"call ");
            if (!jumpDISASM(input, output, mas_label, size)) close;
            addres++;
            status=1;
        }
        if (input_data==RET){
            fprintf(output,"ret\n");
            status=1;
        }
        if (!status) {printf("Incorrect command (%lf)\n",input_data); close;}
        addres++;
    }


    //close all files
    free(mas_label);
    fclose(input);
    fclose(output);
    return 0;
}

