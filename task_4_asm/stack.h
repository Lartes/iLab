#ifndef stackIlab
#define stackIlab

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef double type; //quickly choose type of stack's elements

struct item{
    type value; //element
    struct item* next; //pointer to the next item
};

void create_stack(struct item** begin); //arguments: the address of pointer to the top item

void push_stack(struct item** current, type element); //arguments: the address of pointer to the top item, element you want to add

type pop_stack(struct item** current); //arguments: the address of pointer to the top item; result: element from item

type top_stack(struct item** current); //arguments: the address of pointer to the top item; result: element from item without deleting from stack

void delete_stack(struct item** current); //arguments: the address of pointer to the top item

bool isEmpty_stack(struct item* current); //arguments: the address of the top item; result: true if empty, false if not empty

bool isExist_stack(struct item* current); //arguments: the address of the top item; result: true if exist, false if not exist

int getCount_stack(struct item *current); //arguments: the address of the top item; result: count of elements

#endif
