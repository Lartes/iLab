#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

#ifndef stackIlab
#define stackIlab

#define throw(a,b) {myexc one((a),(b)); throw one;}

class myexc{
    public:
        myexc(char name[10], int error);
        ~myexc();
        void what();
    private:
        myexc();
        char name_[10];
        int error_;
};

myexc::myexc(char name[10], int error){
    strcpy(name_,name);
    error_=error;
}

myexc::~myexc(){
    strcpy(name_,"");
    error_=-1;
}

void myexc::what(){
    printf("Error in function %s: ",name_);
    switch(error_){
    case 1: printf("stack is empty\n"); break;
    case 2: printf("memory didn't allocated\n"); break;
    default: printf("nondefinite error\n"); break;
    }
}



template <typename T>
class Cstack{
    public:
        Cstack();
        ~Cstack();
        void push(T element); //arguments: the address of pointer to the top item, element you want to add
        T pop(); //arguments: the address of pointer to the top item; result: element from item
        bool isEmpty(); //arguments: the address of the top item; result: true if empty, false if not empty
        int getCount(); //arguments: the address of the top item; result: count of elements
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
    begin_=NULL;
    count_=0;
}

template <typename T>
void Cstack<T>::push(T element){
    try{
    struct item *temp=begin_;
    begin_=new struct item;
    if (begin_==NULL) throw ("push",2);
    begin_->value=element;
    if (temp==NULL)
        begin_->next=NULL;
    else
        begin_->next=temp;
    count_++;
    }
    catch(myexc error){
    error.what();
    exit(0);
    }
    catch(...){};
}

template <typename T>
T Cstack<T>::pop(){
    try{
    if (begin_==NULL) throw ("pop",1);  //when assert showed, you know what the error
    T element=begin_->value;
    struct item *temp=begin_;
    begin_=begin_->next;
    delete temp;
    count_--;
    return element;
    }
    catch(myexc error){
    error.what();
    exit(0);
    }
}

template <typename T>
Cstack<T>::~Cstack(){
    struct item* temp=NULL;
    while (begin_!=NULL){
        temp=begin_;
        begin_=begin_->next;
        delete temp;
    };
}

template <typename T>
bool Cstack<T>::isEmpty(){
    if (begin_==NULL) return true;
    return false;
}

template <typename T>
int Cstack<T>::getCount(){
    return count_;
}

#endif
