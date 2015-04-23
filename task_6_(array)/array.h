#ifndef CArrayh
#define CArrayh

#include<cassert>
#include<iostream>
#include<string.h>

template <typename Data_T>
class CArray{
public:
    CArray(int size);
    ~CArray();
    Data_T* at(int n);
    void add_mem(int how);
    int fsize();
    Data_T& operator[] (int n);
    CArray<Data_T>& operator+ (CArray<Data_T>& a);
private:
    CArray();
    Data_T* data_;
    int size_;
};

template <typename Data_T>
CArray <Data_T>::CArray(int size):
    data_(new Data_T[size]),
    size_(size)
    {
    memset(data_,0,sizeof(Data_T)*size);
    }


template <typename Data_T>
CArray <Data_T>::~CArray(){
    delete[] data_;
    data_=NULL;
    size_=0;
}

template <typename Data_T>
Data_T* CArray <Data_T>::at(int n){
    assert(data_ != NULL);
    assert(n>=0 && n<size_);
    return &data_[n];
}

template <typename Data_T>
void CArray <Data_T>::add_mem(int how){
    int i;
    Data_T* temp = new Data_T[size_+how+10];
    for (i=0;i<size_;i++){
        temp[i]=data_[i];
    }
    Data_T* temp2=data_;
    data_=temp;
    size_=size_+how+10;
    free(temp2);
}

template <typename Data_T>
int CArray <Data_T>::fsize(){
    return size_;
}

template <typename Data_T>
Data_T& CArray <Data_T>::operator[] (int n){//& - ссылка
    assert(data_ != NULL);
    assert(n>=0 && n<size_);
    return data_[n];
}

template <typename Data_T>
CArray<Data_T>& CArray <Data_T>::operator+ (CArray<Data_T>& a){
    int i, flag=0, maximum=a.fsize();
    if (size_>a.fsize()){
        maximum=size_;
        flag=1;
    }
    CArray* temp;
    temp=new CArray<Data_T>(maximum);
    temp->size_=maximum;
    if (flag){
        for (i=0;i<a.fsize();i++){
            (*temp)[i]=data_[i]+a[i];
        }
        for (i=a.fsize();i<size_;i++){
            (*temp)[i]=data_[i];
        }
    }
    else{
        for (i=0;i<size_;i++){
            (*temp)[i]=data_[i]+a[i];
        }
        for (i=size_;i<a.fsize();i++){
            (*temp)[i]=a[i];
        }
    }
    return *temp;
}

#endif
