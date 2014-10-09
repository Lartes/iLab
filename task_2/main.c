#include"function.h"

int main(){
    int a;
    printf("Choose program:\n");
    printf("1 - Weighing(var.1 C)\n");
    printf("2 - Table of nice words(var.1 D)\n");
    printf("3 - Sum of four square(var.3 Ñ)\n");
    scanf("%d",&a);
    printf("****************************\n");
    switch(a){
    case 1: weighing(); break;
    case 2: good_words(); break;
    case 3: four_square(); break;}
    return 0;
}
