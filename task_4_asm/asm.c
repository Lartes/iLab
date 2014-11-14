#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"
#include"functions_asm.h"

#define close close(input,output,output_name,mas_label)//ALL FUNCTIONS AND ARGUMENTS OF FUNCTIONS MUST SEPARATED BY ONE SPACE AT LEAST

int main(int argv, char* argc[]){


    //initialization of variables
    double input_data_doub;
    char input_data_str[10], input_name[20], output_name[20], sys[20];
    int status, size=5, i=0, addres=0;
    double wr;
    struct label *mas_label=(struct label*)calloc(size,sizeof(struct label));
    FILE *input=NULL, *output=NULL;


    //open input and output files
    if (argv==3){                         //from command line
        strcpy(input_name,argc[1]);
        strcpy(output_name,argc[2]);
    }
    else{ if (argv==1){
             strcpy(input_name,"input.txt"); //default
             strcpy(output_name,"output.txt");
         }
         else {printf("Input names of file aren't full\n"); exit(0);}
    }

    if ((input=fopen(input_name, "r"))==NULL)
        {printf("Cannot open input file\n"); close;}
    if ((output=fopen(output_name, "w"))==NULL)
        {printf("Cannot create output file\n"); close;}


    //searching for labels
    i=0;
    while (fscanf(input,"%s",input_data_str)!=EOF){
        addres++;
        if (input_data_str[strlen(input_data_str)-1]==':'){
            if ((input_data_doub=addres_label(mas_label,i,input_data_str))!=-1)
                {printf("Duplication label\n"); close;}
            addres--;
            strncpy((mas_label[i]).name, input_data_str, strlen(input_data_str)-1);
            (mas_label[i]).addres=addres;
            i++;
            if (i==size) mas_label=(struct label*)realloc(mas_label,(size+=5)*sizeof(struct label));
        }
    }
    size=i; //number of labels
    fclose(input); //можно ли не закрывать файл


    //writing information about labels to file
    if (strchr(output_name,'.')!=NULL){   //create name of file
        strncpy(sys,output_name,strchr(output_name,'.')-output_name);
        sys[strchr(output_name,'.')-output_name]='\0';
    }
    else strcpy(sys,output_name);
    strcat(sys,"_sys.txt");

    if ((input=fopen(sys, "w"))==NULL) //creating system file with labels НУЖНО ЛИ ПИСАТЬ В БИНАРНЫЙ ФАЙЛ ТУТ???
        {printf("Cannot write system file\n"); close;}
    fprintf(input, "%d\n", size);
    for (i=0;i<=size-1;i++){
        fprintf(input,"%s %d\n", (mas_label[i]).name, (mas_label[i]).addres);
    }
    fclose(input);


    //reopen input file for general reading
    if ((input=fopen(input_name, "r"))==NULL)
        {printf("Cannot open file\n"); close;}


    //reading
    while (fscanf(input,"%s",input_data_str)!=EOF){
        status=0;
        if (!stricmp(input_data_str,"push")){    //stricmp - compare strings without register
            wr=PUSH;
            fwrite(&wr,sizeof(double),1,output);
            if (fscanf(input,"%lf",&input_data_doub)>0){ //КАК ОН ПРЕОБРАЗУЕТ INFINITY и NAN
                fwrite(&input_data_doub,sizeof(double),1,output);
            }
            else
                {printf("Incorrect command argument in PUSH\n"); close;}
            status=1;
            *input_data_str='q';
        }
        if (!stricmp(input_data_str,"add")){
            wr=ADD;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"sub")){
            wr=SUB;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"mul")){
            wr=MUL;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"div")){
            wr=DIV;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"sqrt")){
            wr=SQRT;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"pop_ax")){
            wr=POP_AX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"push_ax")){
            wr=PUSH_AX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"pop_bx")){
            wr=POP_BX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"push_bx")){
            wr=PUSH_BX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"pop_cx")){
            wr=POP_CX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"push_cx")){
            wr=PUSH_CX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"pop_dx")){
            wr=POP_DX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"push_dx")){
            wr=PUSH_DX;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"out")){
            wr=OUT;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"end")){
            wr=END;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"jmp")){
            wr=JMP;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close; //reading label and convert it
            status=1;
        }
        if (!stricmp(input_data_str,"jz")){
            wr=JZ;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close;
            status=1;
        }
        if (!stricmp(input_data_str,"jnz")){
            wr=JNZ;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close;
            status=1;
        }
        if (!stricmp(input_data_str,"je")){
            wr=JE;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close;
            status=1;
        }
        if (!stricmp(input_data_str,"jl")){
            wr=JL;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close;
            status=1;
        }
        if (!stricmp(input_data_str,"jg")){
            wr=JG;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close;
            status=1;
        }
        if (!stricmp(input_data_str,"cmp")){
            wr=CMP;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!stricmp(input_data_str,"call")){
            wr=CALL;
            fwrite(&wr,sizeof(double),1,output);
            if (!jumpASM(input, output, mas_label, size)) close; //reading label and convert it
            status=1;
        }
        if (!stricmp(input_data_str,"ret")){
            wr=RET;
            fwrite(&wr,sizeof(double),1,output);
            status=1;
        }
        if (!status && input_data_str[strlen(input_data_str)-1]!=':') {printf("Incorrect command (%s)\n",input_data_str); close;}

    }


    //close all files
    free(mas_label);
    fclose(input);
    fclose(output);
    return 0;
}

