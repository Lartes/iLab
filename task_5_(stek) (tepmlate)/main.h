#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#ifndef stackIlab
#define stackIlab

template <typename T>
class Cstack{
    public:
        Cstack();
        ~Cstack();
        void push_stack(T element); //arguments: the address of pointer to the top item, element you want to add
        T pop_stack(); //arguments: the address of pointer to the top item; result: element from item
        bool isEmpty_stack(); //arguments: the address of the top item; result: true if empty, false if not empty
        int getCount_stack(); //arguments: the address of the top item; result: count of elements
    private:
        struct item{
            T value; //element
            struct item* next; //pointer to the next item
        };
        struct item* begin_;
        int count_;
};

template <typename T>
Cstack<T>::Cstack(){
    begin_=new struct item;
    begin_->value=0;
    begin_->next=NULL;
    count_=0;
}

template <typename T>
void Cstack<T>::push_stack(T element){
    struct item *temp=begin_;
    begin_=new struct item;
    begin_->value=element;
    begin_->next=temp;
    count_++;
}

template <typename T>
T Cstack<T>::pop_stack(){
    assert((!isEmpty_stack()));  //when assert showed, you know what the error
    T element=begin_->value;
    struct item *temp=begin_;
    begin_=begin_->next;
    delete temp;
    count_--;
    return element;
}

template <typename T>
Cstack<T>::~Cstack(){
    struct item* temp=NULL;
    while (begin_->next!=NULL){
        temp=begin_;
        begin_=begin_->next;
        delete temp;
    };
    delete begin_;
    begin_=NULL;
}

template <typename T>
bool Cstack<T>::isEmpty_stack(){
    if (begin_->next==NULL) return true; else return false;
}

template <typename T>
int Cstack<T>::getCount_stack(){
    return count_;
}

#endif
