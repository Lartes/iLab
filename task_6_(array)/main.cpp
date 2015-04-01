#include<iostream>
#include"array.h"

using namespace std;
typedef int type;

int main(){
    CArray <type> masA (2);
    CArray <type> masB (3);
    CArray <type> masC (1);
    masA[0]=1;
    masA[1]=2;
    masB[0]=3;
    masB[2]=4;
    masC=masA+masB;
    cout<<"[0]="<<masC[0]<<" [1]="<<masC[1]<<" [2]="<<masC[2]<<endl;
    masC=masB+masA;
    cout<<"[0]="<<masC[0]<<" [1]="<<masC[1]<<" [2]="<<masC[2]<<endl;
    return 0;
}
