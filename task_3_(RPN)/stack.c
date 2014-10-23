#include "stack.h"

void myStack_push (myStack *S, type value)
{
    if (S->allocated_size == 0)
    {
        S->allocated_size = 100;
        S->A = (type *)calloc(S->allocated_size, sizeof(type));
        if (S->A == NULL)
        {
            printf("Memory not given... Can't continue algorithm.\n");
            exit(-1);
        }
    }
    else if (myStack_is_full(S))
    {
        S->allocated_size *= 2;
        S->A = (type *)realloc(S->A, S->allocated_size*sizeof(type));
        if (S->A == NULL)
        {
            printf("Memory not given... Can't continue algorithm.\n");
            exit(-1);
        }
    }
    S->A[S->number] = value;
    S->number ++;
}

type myStack_pop (myStack *S)
{
    if (myStack_is_empty(S))
        return -1;
    S->number --;
    type value = S->A[S->number];
    return value;
}

type myStack_top(const myStack *S)
{
    return S->A[S->number - 1];
}

int myStack_is_empty (const myStack *S)
{
    return S->number == 0;
}

int myStack_is_full(const myStack *S)
{
    return S->number == S->allocated_size;
}

void myStack_init (myStack *S)
{
    S->A = NULL;
    S->allocated_size = 0;
    S->number = 0;
}
void myStack_delete (myStack *S)
{
    free(S->A);
    S->A = NULL;
    S->allocated_size = 0;
    S->number = 0;
}
