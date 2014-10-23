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
/*����������� �� �����:
1. ����� myStack_delete �� ������ ����� ���������� ��������
2. myStack_top �� ������� ����� �������� ���������
3. myStack_push � ������ ���� �������� ���������
4. myStack_pop �� ������� ����� �������� ���������
5. �� ������� ����� ������ ������������� -1
6. ��� ������� stack_count; ������ ����� ����� ������ stack.number, �� �������� ������� � ����������� �����, ����� ��� ��������!
7. ������ ������ �������� ��� ������ � ����� (����� �������� �����������, ��� � ��� ������)
8. ��� ��������� �� ��������, �� ���������� � ������������ ���������
*/
