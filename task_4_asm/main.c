#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"

int main(int argv, char* argc[]){ //ВЫХОД, ЗАКРЫВАЯ ВСЁ И ОСВОБОЖДАЯ ПАМЯТЬ; ПРОВЕРКА ОШИБОК
    double data; //initialization of variables
    int size=100, i=0;
    char input_name[20], output_name[20];

    //open input and output files
    if (argv==2){                         //from command line
        strcpy(input_name,argc[1]);
    }
    else{ if (argv==1){
             strcpy(input_name,"output.txt"); //default
         }
         else {printf("Input name of file isn't correct\n"); exit(0);}
    }

    if (strchr(input_name,'.')!=NULL){   //create name of output file
        strncpy(output_name,input_name,strchr(input_name,'.')-input_name);
        output_name[strchr(input_name,'.')-input_name]='\0';
    }
    else strcpy(output_name,input_name);
    strcat(output_name,"_res.txt");


    double *input_data=(double*)calloc(size,sizeof(double)); //Array of input data
    double *input_data0=NULL;

    struct item *stack=NULL; //stack for calculations
    create_stack(&stack);

    type regAX, regBX; //registers

    remove(output_name); //file to display the results

    FILE *input=NULL; //file with input data
    if ((input=fopen(input_name, "r"))==NULL)
        {printf("Can not open file\n"); exit(0);}
    while (fread(&data,sizeof(double),1,input)>0){ //reading input data
        input_data[i]=data;
        i++;
        if (i>=size) input_data=(double*)realloc(input_data,size+=100);
    }
    if (input_data[i-1]!=END)
        {printf("END didn't find\n"); exit(0);} //incorrect completion of the program
    fclose(input);


    input_data0=input_data;
    while (*input_data!=END){ //processing the input data
        if (abs(*input_data-(int)*input_data)>0.00001) //incorrect command
            {printf("Logical error or incorrect input\n"); exit(0);}
        switch ((int)*input_data){
        case PUSH: push(&stack,*(++input_data)); break;
        case ADD: add(&stack);  break;
        case MUL: mul(&stack);  break;
        case POP_AX: popReg(&stack, &regAX);  break;
        case PUSH_AX: pushReg(&stack, regAX);  break;
        case POP_BX: popReg(&stack, &regBX);  break;
        case PUSH_BX: pushReg(&stack, regBX);  break;
        case OUT: out(&stack, output_name);  break;
        case JMP: input_data++;
                  input_data=jmp(input_data0,(int)*(input_data));
                  break;
        case JZ:  input_data++;
                  input_data=jz(&stack,input_data0,input_data,(int)*(input_data));
                  break;
        case JNZ: input_data++;
                  input_data=jnz(&stack,input_data0,input_data,(int)*(input_data));
                  break;
        case CMP: cmp(&stack); break;
        default: printf("Logical error\n");
                 exit(0);
        }
        input_data++;
    }

    free(input_data0); //NOT input_data!!!
    delete_stack(&stack);
    return 0;
}
