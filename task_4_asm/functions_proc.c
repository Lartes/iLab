#include"functions_proc.h"

void stop(FILE* input, char output_name[20], double *input_data, double *input_data0, struct item **stack,  struct item **stack_func){
    if (input!=NULL)               //некорректное завершение при некорректном окончании файла!!!!
        fclose(input);
    remove(output_name);
    if (input_data0==NULL)
        free(input_data);
    else free(input_data0);
    delete_stack(stack);
    delete_stack(stack_func);
    exit(0);
}

int no_enough(char* s,int n){//НЕ ПРОИСХОДИТ КОРРЕКТНОГО ЗАКРЫТИЯ ГЛАВНОЙ ПРОГРАММЫ
    FILE *result=NULL;
    if ((result=fopen("error.txt", "w"))==NULL) {printf("Cannot write file\n"); exit(0);}
    fprintf(result,"No enough arguments for %s(%d)",s,n);
    fclose(result);
    printf("ERROR. See error.txt\n");
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

int sub(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("ADD",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("ADD",n);
    push_stack(stack, a-b);
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

int div_my(struct item **stack){
    static int n=0;
    n++;
    double a,b;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("MUL",n);
    if (!isEmpty_stack(*stack)) b=pop_stack(stack); else no_enough("MUL",n);
    if (b==0) {printf("Division by zero!"); exit(0);}  //НЕКОРРЕКТНОЕ ЗАКРЫТИЕ
    push_stack(stack, a/b);
    return 0;
}

int sqrt_my(struct item **stack){
    static int n=0;
    n++;
    double a;
    if (!isEmpty_stack(*stack)) a=pop_stack(stack); else no_enough("MUL",n);
    if (a<0) {printf("Argument of SQRT is less than zero"); exit(0);} //НЕКОРРЕКТНОЕ ЗАКРЫТИЕ
    push_stack(stack, sqrt(a));   // !!!!SQRT!!!!
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

double *je(struct item **stack, double *input_data0, double *input_data, int pointer){
    static int n=0;
    type a,b;

    n++;
    if (isEmpty_stack(*stack)) no_enough("JE",n);
    a=pop_stack(stack);
    if (isEmpty_stack(*stack)) no_enough("JE",n);
    b=pop_stack(stack);
    if (abs(a-b)<0.000000001) //МОЖНО ЛИ a=b НА ТИПЕ double?
        return input_data0+pointer-1;
    else
        return input_data;
}

double *jl(struct item **stack, double *input_data0, double *input_data, int pointer){
    static int n=0;
    type a,b;

    n++;
    if (isEmpty_stack(*stack)) no_enough("JL",n);
    a=pop_stack(stack);
    if (isEmpty_stack(*stack)) no_enough("JL",n);
    b=pop_stack(stack);
    if (a<b)
        return input_data0+pointer-1;
    else
        return input_data;
}

double *jg(struct item **stack, double *input_data0, double *input_data, int pointer){
    static int n=0;
    type a,b;

    n++;
    if (isEmpty_stack(*stack)) no_enough("JG",n);
    a=pop_stack(stack);
    if (isEmpty_stack(*stack)) no_enough("JG",n);
    b=pop_stack(stack);
    if (a>b)
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

double *ret(struct item **stack, double *input_data0){
    static int n=0;
    long int pointer;

    n++;
    if (isEmpty_stack(*stack)) no_enough("RET",n);
    pointer=(long int)pop_stack(stack);
    return input_data0+pointer-1;
}
