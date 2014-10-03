#include"solve_sqr.h"

void solve_sqr(double a,double b,double c,double *x1,double *x2, int *root_amount){
if (a==0){
        if (b==0){
            if (c==0){
                *root_amount=INFINITY_ROOTS;  //An infinite number of roots
            }
            else
                *root_amount=NO_ROOTS;  //No roots
        }
        else{
            *x1=-c/b;  //Linear equation - one root
            *root_amount=ONE_ROOT;
        }
    }
    else{
        double d=b*b-4*a*c; //Calculate the discriminant
        if (d<0){
            *root_amount=NO_ROOTS;
        }
        else{
            if (d==0){
                *x1=-b/(2*a); //Complete square - one root
                *root_amount=ONE_ROOT;
            }
            else{
                *x1=(-b+sqrt(d))/(2*a); //First root
                *x2=(-b-sqrt(d))/(2*a); //Second root
            }
        }
    }

}

void out(double x1, double x2, int root_amount){
switch(root_amount){
        case NO_ROOTS: printf("The equation has no roots");
        break;
        case ONE_ROOT: printf("The equation has one root x=%f", x1);
        break;
        case TWO_ROOTS: printf("The equation has two roots x1=%f, x2=%f",x1,x2);
        break;
        case INFINITY_ROOTS: printf("Equation has an infinite number of roots");
        break;
        default: printf("Error");
        break;
    }
}
