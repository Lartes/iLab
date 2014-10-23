#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"

int main(){
    myStack stack;
    myStack_init(&stack);
    int input; //type of the read group
    float a,b;
    char group[10];

    do{
        read(group);
        input=what_is_input(group);
        if (input==NUMBER) myStack_push(&stack, atof(group));
        else{ if (input!=EXIT && input!=INCORRECT_SYMBOL){
            if (!myStack_is_empty(&stack)) a=myStack_pop(&stack); else input=ERROR;
            if (!myStack_is_empty(&stack)) b=myStack_pop(&stack); else input=ERROR;
        }}
        switch (input){
            case PLUS: myStack_push(&stack, b+a); break;
            case MINUS: myStack_push(&stack, b-a); break;
            case MULT: myStack_push(&stack, b*a); break;
            case DIV: myStack_push(&stack, (double)b/a); break;
            case INCORRECT_SYMBOL: printf("You typed incorrect symbol!"); exit(0); break;
            case ERROR: printf("Your expression is incorrect!"); exit(0); break; // if the number of arguments is not enough for operations
        };
    }while (input!=EXIT);
    if (stack.number!=1) {printf("Your expression is incorrect!"); exit(0);} // if the number of operations is not enough for arguments
    printf("%lf",myStack_pop(&stack));
    myStack_delete(&stack);
    return 0;
}
/*Комментарии по стеку:
1. после myStack_delete со стеком можно продолжать работать
2. myStack_top от пустого стека выбивает программу
3. myStack_push в пустой стек выбивает программу
4. myStack_pop от пустого стека выбивает программу
5. из пустого стека всегда вытаскивается -1
6. нет функции stack_count; вместо этого нужно делать stack.number, но пришлось вникать в конструкцию стека, чтобы это выяснить!
7. нельзя быстро поменять тип данных в стеке (опять пришлось разбираться, что и где менять)
8. нет пояснений по функциям, их аргументам и возвращаемым значениям
*/
