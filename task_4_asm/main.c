#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"

#define stop stop(input,output_name,input_data,input_data0,&stack,&stack_func)

// отрицательные корни
// !!!!SQRT!!!!
// !!!!SQRT!!!!
// !!!!SQRT!!!!
// !!!!SQRT!!!!
// !!!!SQRT!!!!

int main(int argv, char* argc[]){ //ПРОВЕРКА ОШИБОК

    //initialization
    double data; //initialization of variables
    int size=100, i=0;
    char input_name[20], output_name[20];
    struct item *stack=NULL; //stack for calculations
    create_stack(&stack);
    struct item *stack_func=NULL; //stack for functions
    create_stack(&stack_func);
    double *input_data=(double*)calloc(size,sizeof(double)); //Array of input data
    double *input_data0=NULL;
    type regAX, regBX, regCX, regDX; //registers
    FILE *input=NULL; //file with input data
    remove("error.txt"); //remove old file with errors


    //open input and output files
    if (argv==2){                         //from command line
        strcpy(input_name,argc[1]);
    }
    else{ if (argv==1){
             strcpy(input_name,"output.txt"); //default
         }
         else {printf("Input name of file isn't correct\n"); stop;}
    }

    if (strchr(input_name,'.')!=NULL){   //create name of output file
        strncpy(output_name,input_name,strchr(input_name,'.')-input_name);
        output_name[strchr(input_name,'.')-input_name]='\0';
    }
    else strcpy(output_name,input_name);
    strcat(output_name,"_res.txt");

    remove(output_name); //file to display the results

    if ((input=fopen(input_name, "r"))==NULL)
        {printf("Can not open file\n"); stop;}
    while (fread(&data,sizeof(double),1,input)>0){ //reading input data
        input_data[i]=data;
        i++;
        if (i>=size) input_data=(double*)realloc(input_data,size+=100);
    }
    fclose(input);
    input_data0=input_data;
    if (input_data[i-1]!=END && input_data[i-1]!=RET)
        {printf("End of file with program is incorrect\n");  stop;} //incorrect completion of the program


    while (*input_data!=END){ //processing the input data
        if (abs(*input_data-(int)*input_data)>0.00001) //incorrect command
            {printf("Logical error or incorrect input\n"); stop;}
        switch ((int)*input_data){
        case PUSH: push(&stack,*(++input_data)); break;
        case ADD: add(&stack);  break;
        case SUB: sub(&stack);  break;
        case MUL: mul(&stack);  break;
        case DIV: div_my(&stack);  break;
        case SQRT: sqrt_my(&stack);  break;
        case POP_AX: popReg(&stack, &regAX);  break;
        case PUSH_AX: pushReg(&stack, regAX);  break;
        case POP_BX: popReg(&stack, &regBX);  break;
        case PUSH_BX: pushReg(&stack, regBX);  break;
        case POP_CX: popReg(&stack, &regCX);  break;
        case PUSH_CX: pushReg(&stack, regCX);  break;
        case POP_DX: popReg(&stack, &regDX);  break;
        case PUSH_DX: pushReg(&stack, regDX);  break;
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
        case JE:  input_data++;
                  input_data=je(&stack,input_data0,input_data,(int)*(input_data));
                  break;
        case JL:  input_data++;
                  input_data=jl(&stack,input_data0,input_data,(int)*(input_data));
                  break;
        case JG:  input_data++;
                  input_data=jg(&stack,input_data0,input_data,(int)*(input_data));
                  break;
        case CMP: cmp(&stack); break;
        case CALL:input_data++;
                  push_stack(&stack_func, input_data-input_data0+1);
                  input_data=jmp(input_data0,(int)*(input_data));
                  break;
        case RET: input_data=ret(&stack_func,input_data0);
                  break;
        default: printf("Logical error\n");
                 stop;
        }
        input_data++;
    }

    free(input_data0); //NOT input_data!!!
    delete_stack(&stack);
    delete_stack(&stack_func);
    printf("OK. See %s\n",output_name);
    return 0;
}
