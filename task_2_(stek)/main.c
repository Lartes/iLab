#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"

enum{
    PUSH=1,
    POP,
    COUNT,
    EXIT,
};

int main(){
    struct item *stack=NULL;  //initialization is required for assert
    int new_element, user_choise;
    create_stack(&stack);
    do{
    printf("************\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Get count\n");
    printf("4 - Exit\n");
    printf("************\n");
    scanf("%d", &user_choise);
    switch (user_choise){
    case PUSH: printf("Enter element\n");
            scanf("%d",&new_element);
            push_stack(&stack, new_element);
            break;
    case POP: if (!isEmpty_stack(stack)){
                printf("_________________%d\n", pop_stack(&stack));
                }
            else{
                printf("_________________Stack is empty\n");
            }
            break;
    case COUNT: printf("______%d\n",getCount_stack(stack));
                break;
    case EXIT: delete_stack(&stack);
               break;
    };
    } while (user_choise!=EXIT);
    return 0;
}
