#include<stdio.h>
#include<stdbool.h>
#include"stek.h"

enum{
    PUSH=1,
    POP,
    COUNT,
    EXIT,
};

void main(){
    struct item *stek;
    int new_element, user_choise;
    creat_stek(&stek);
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
            push_stek(&stek, new_element);
            break;
    case POP: if (!isEmpty_stek(stek)){
                printf("_________________%d\n", pop_stek(&stek));
                }
            else{
                printf("_________________Stek is empty\n");
            }
            break;
    case COUNT: printf("______%d\n",getCount_stek(stek));
                break;
    case EXIT: delete_stek(&stek);
               break;
    };
    } while (user_choise!=EXIT);

}
