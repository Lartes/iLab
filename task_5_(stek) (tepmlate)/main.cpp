#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"main.h"

enum{
    PUSH=1,
    POP,
    COUNT,
    EXIT,
};

int main(){
    Cstack<int> one;  //initialization is required for assert
    int new_element, user_choise;
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
            one.push_stack(new_element);
            break;
    case POP: if (!one.isEmpty_stack()){
                printf("_________________%d\n", one.pop_stack());
                }
            else{
                printf("_________________Stack is empty\n");
            }
            break;
    case COUNT: printf("______%d\n",one.getCount_stack());
                break;
    case EXIT: break;
    };
    } while (user_choise!=EXIT);
    return 0;
}
