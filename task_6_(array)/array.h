#ifndef CArray
#define CArray

#include<cassert>
#include<iostream>

template <typename Data_T>
class CArray{
public:
    CArray(int size);
    ~CArray();
    Data_t* at(int n);
private:
    CArray();
    Data_T* data_;
    int size_;
};

template <typename Data_T>
CArray <Data_t>::CArray(int size):
    data_(new Data_t[size]),
    size_(0)
    {
    setmem(data_,0,sizeof(Data_t)*size);
    }


template <typename Data_T>
CArray <Data_t>::~CArray(){
    delete[] data_;
    data_=NULL;
    size_=0;
}

template <typename Data_T>
Data_t* CArray <Data_t>::at(int n){
    assert(data_ != NULL);
    assert(n>=0 && n<size_);
    return &data_[n];
}

/*template <typename Data_T>
void operator +(CArray<Data_T>& a, const CArray<Data_T>& b){ //нужно добавить поддержку ассициатисности: CArray Data_t&

}*/

template<typename Data_T>
Data_T& operator[] (int n){//& - ссылка
    assert(data_ != NULL);
    assert(n>=0 && n<size_);
    return data_[n];
}

#endif










