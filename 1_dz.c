#include<stdio.h>
#include<math.h>

void kvad(double a,double b,double c,float *x1,float *x2, int *am_root){
if (a==0){
        if (b==0){
            if (c==0){
                *am_root=-1;  //An infinite number of roots
            }
            else
                *am_root=0;  //No roots
        }
        else{
            *x1=-c/b;  //Linear equation - one root
            *am_root=1;
        }
    }
    else{
        double d=b*b-4*a*c; //Calculate the discriminant
        printf("Discriminant D=%f\n",d);
        if (d<0){
            *am_root=0;
        }
        else{
            if (d==0){
                *x1=-b/2/a; //Complete square - one root
                *am_root=1;
            }
            else{
                *x1=(-b+sqrt(d))/2/a; //First root
                *x2=(-b-sqrt(d))/2/a; //Second root
            }
        }
    }

}

int main(){
    double a=0,b=0,c=0;
    int am_root=2;  //q=0 - no, 1 - one, 2 - two, -1 - any
    float x1=0,x2=0,d=0;

    printf("Enter the coefficients of the quadratic equation ax^2+bx+c=0\n");
    scanf("%lg %lg %lg",&a,&b,&c);  //Input variables

    kvad(a,b,c,&x1,&x2,&am_root);

    switch(am_root){
        case 0: printf("The equation has no roots");  //Output
        break;
        case 1: printf("The equation has one root x=%f", x1);
        break;
        case 2: printf("The equation has two roots x1=%f, x2=%f",x1,x2);
        break;
        case -1: printf("Equation has an infinite number of roots");
        break;
        default: printf("Error");
        break;
    }

    return 0;
}
