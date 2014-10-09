#ifndef stekIlab
#define stekIlab

#include<stdio.h>
#include<stdbool.h>

#define type int //quickly choose type of stek's elements

struct item{
    type value; //element
    struct item* next; //pointer to the next item
};

void creat_stek(struct item** begin); //arguments: the address of pointer to the top item

void push_stek(struct item** current, type element); //arguments: the address of pointer to the top item, element you want to add

type pop_stek(struct item** current); //arguments: the address of pointer to the top item; result: element from item

void delete_stek(struct item** current); //arguments: the address of pointer to the top item

bool isEmpty_stek(struct item* current); //arguments: the address of the top item; result: true if empty, false if not empty

int getCount_stek(struct item *current); //arguments: the address of the top item; result: count of elements

#endif
