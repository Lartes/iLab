#include"stek.h"

void creat_stek(struct item **begin){
    *begin=(struct item*)calloc(1,sizeof(**begin));
    (**begin).value=NULL;
    (**begin).next=NULL;
    return 0;
}

void push_stek(struct item **current, type element){
    struct item *temp=*current;
    *current=(struct item*)calloc(1,sizeof(**current));
    (**current).value=element;
    (**current).next=temp;
    return 0;
}

type pop_stek(struct item **current){
    type element=(**current).value;
    struct item *temp=*current;
    *current=(**current).next;
    free(temp);
    return element;
}

void delete_stek(struct item** current){
    struct item* temp=NULL;
    while ((**current).value!=NULL){
        temp=*current;
        *current=(**current).next;
        free(temp);
    };
    free(*current);
    return 0;
}

bool isEmpty_stek(struct item *current){
    if ((*current).next==NULL) return true; else return false;
}

int getCount_stek(struct item *current){
    int number_of_elements=0;
    while ((*current).next!=NULL){
        number_of_elements++;
        current=(*current).next;
    }
    return number_of_elements;
}
