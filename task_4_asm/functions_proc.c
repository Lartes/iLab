#include"functions_proc.h"

int no_enough(char* s,int n){
    FILE *result=NULL;
    if ((result=fopen("result.txt", "a"))==NULL) {printf("Cannot write file"); exit(0);}
    fprintf(result,"No enough arguments for %s(%d)",s,n);
    fclose(result);
    printf("ERROR");
    exit(0);
}

int push(struct item **stack, type new_element){
    push_stack(stack, new_element);
}

int add(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("ADD",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("ADD",n);
    push_stack(stack, b+a);
}

int mul(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("MUL",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("MUL",n);
    push_stack(stack, b*a);
}

int out(struct item **stack){
    static int n=0;
    n++;
    FILE *result=NULL;
    if ((result=fopen("result.txt", "a"))==NULL) {printf("Cannot write file"); exit(0);}
    if (!isEmpty_stack(*stack)) fprintf(result,"%lf\n",top_stack(stack)); else no_enough("OUT",n);
    fclose(result);
}

double *jmp(double *input_data0, int pointer){
    return input_data0+pointer-1;
}
