#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"functions_proc.h"

int main(){
    double data; //initialization of variables
    int size=100, i=0;
    int status;

    double *input_data=(double*)calloc(size,sizeof(double)); //Array of input data
    double *input_data0=NULL;

    struct item *stack=NULL; //stack for calculations
    create_stack(&stack);

    remove("result.txt"); //file to display the results

    FILE *input=NULL; //file with input data
    if ((input=fopen("output.txt", "r"))==NULL)
        {printf("Can not open file"); exit(0);}
    while ((status=fscanf(input,"%lf",&data))>0 && data!=END){ //reading input data
        input_data[i]=data;
        i++;
        if (i>=size) input_data=(double*)realloc(input_data,size+=100);
    }
    if (status==0)
        {printf("Incorrect Input file"); exit(0);} //file contain incorrect characters
    if (data!=END)
        {printf("END didn't find"); exit(0);} //incorrect completion of the program
    input_data[i]=data;
    fclose(input);

    input_data0=input_data;
    while (*input_data!=END){ //processing the input data
        if (abs(*input_data-(int)*input_data)>0.00001) //incorrect command
            {printf("Logical error"); exit(0);}
        switch ((int)*input_data){
        case PUSH: push(&stack,*(++input_data)); break;
        case ADD: add(&stack);  break;
        case MUL: mul(&stack);  break;
        case OUT: out(&stack);  break;
        case JMP: *input_data=END;  //for prevent an infinite loop
                  input_data=jmp(input_data0,(int)*(++input_data));
                  break;
        default: printf("Logical error");
                 exit(0);
        }
        input_data++;
    }

    free(input_data0); //NOT input_data!!!
    delete_stack(&stack);
}
