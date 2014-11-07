#include"functions_proc.h"

int no_enough(char* s,int n){
    FILE *result=NULL;
    if ((result=fopen("result.txt", "a"))==NULL) {printf("Cannot write file\n"); exit(0);}
    fprintf(result,"No enough arguments for %s(%d)",s,n);
    fclose(result);
    printf("ERROR. See result.txt\n");
    exit(0);
    return 0;
}

int push(struct item **stack, type new_element){
    push_stack(stack, new_element);
    return 0;
}

int add(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("ADD",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("ADD",n);
    push_stack(stack, b+a);
    return 0;
}

int mul(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("MUL",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("MUL",n);
    push_stack(stack, b*a);
    return 0;
}

int popReg(struct item **stack,type *reg){
    static int n=0;
    n++;
    if (!isEmpty_stack(*stack)) *reg=pop_stack(stack); else no_enough("POP to register",n);
    return 0;
}

int pushReg(struct item **stack,type reg){
    push_stack(stack, reg);
    return 0;
}

int out(struct item **stack, char output_name[20]){
    static int n=0;
    n++;
    FILE *result=NULL;
    if ((result=fopen(output_name, "a"))==NULL) {printf("Cannot write file\n"); exit(0);}
    if (!isEmpty_stack(*stack)) fprintf(result,"%lf\n",top_stack(stack)); else no_enough("OUT",n);
    fclose(result);
    return 0;
}

double *jmp(double *input_data0, int pointer){
    return input_data0+pointer-1;
}

double *jz(struct item **stack, double *input_data0, double *input_data, int pointer){
    static int n=0;

    n++;
    if (isEmpty_stack(*stack)) no_enough("JZ",n);
    if (pop_stack(stack)==0)
        return input_data0+pointer-1;
    else
        return input_data;
}

double *jnz(struct item **stack, double *input_data0, double *input_data, int pointer){
    static int n=0;

    n++;
    if (isEmpty_stack(*stack)) no_enough("JNZ",n);
    if (pop_stack(stack)!=0)
        return input_data0+pointer-1;
    else
        return input_data;
}

int cmp(struct item **stack){
    type a,b;
    static int n=0;

    n++;
    if (isEmpty_stack(*stack)) no_enough("CMP",n);
    a=pop_stack(stack);
    if (isEmpty_stack(*stack)) no_enough("CMP",n);
    b=pop_stack(stack);

    if (abs(a-b)<0.000000001)
        push_stack(stack, 0);
    else  if (a>b)
                push_stack(stack, 1);
          else
                push_stack(stack, -1);
    return 0;
}
