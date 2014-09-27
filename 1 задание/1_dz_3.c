#include"solve_sqr.h"

/**
@mainpage Program for solving the quadratic equation
*/

int main(){
    double a=0,b=0,c=0;
    int root_amount=TWO_ROOTS;
    double x1=0,x2=0,d=0;
    char s='-';

    printf("Enter the coefficients of the quadratic equation ax^2+bx+c=0\n");
    scanf("%lg %lg %lg", &a, &b, &c);  //Input variables
    scanf("%c",&s);
    if (s!=10){       //Check the validity of data
        printf("It is not a number");
    } else{
        solve_sqr(a,b,c,&x1,&x2,&root_amount);
        out(x1,x2,root_amount);
    }
    return 0;
}
