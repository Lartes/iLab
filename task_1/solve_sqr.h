#include<stdio.h>
#include<math.h>

#ifndef solve_sqrH
#define solve_sqrH

/**
@brief Number of companies found roots
*/

enum root_type {INFINITY_ROOTS, /**<An infinite number of*/
                NO_ROOTS,       /**<No roots*/
                ONE_ROOT,       /**<One root*/
                TWO_ROOTS       /**<Two roots*/
                };

/**
@brief Function of the solution of the equation
@param a,b,c The coefficients of the quadratic equation
@return x1,x2 The roots of a quadratic equation
*/

void solve_sqr(double a,double b,double c,double *x1,double *x2, int *root_amount);

/**
@brief Output function of the roots
@param x1,x2 The roots of a quadratic equation
*/

void out(double x1, double x2, int root_amount);

#endif
