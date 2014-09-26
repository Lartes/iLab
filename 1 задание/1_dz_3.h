#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<C:\Users\Àðò¸ì\Desktop\iLab\solve_sqr.h>

/**
@mainpage Program for solving the quadratic equation
*/

int main(){
    double a=0,b=0,c=0;
    root_amount=TWO_ROOTS;
    double x1=0,x2=0,d=0;

    printf("Enter the coefficients of the quadratic equation ax^2+bx+c=0\n");
    scanf("%lg %lg %lg", &a, &b, &c);  //Input variables

    solve_sqr(a,b,c,&x1,&x2);
    out(x1,x2);

    return 0;
}
