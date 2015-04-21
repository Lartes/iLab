#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"main.h"

using namespace std;

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
    cout<<"************\n";
    cout<<"1 - Push\n";
    cout<<"2 - Pop\n";
    cout<<"3 - Get count\n";
    cout<<"4 - Exit\n";
    cout<<"************\n";
    cin >> user_choise;
    switch (user_choise){
    case PUSH: printf("Enter element\n");
            scanf("%d",&new_element);
            one.push(new_element);
            break;
    case POP: cout<<"element="<<one.pop()<<endl;
            break;
    case COUNT: cout<<"count="<<one.getCount()<<endl;
                break;
    case EXIT: break;
    };
    } while (user_choise!=EXIT);
    return 0;
}
