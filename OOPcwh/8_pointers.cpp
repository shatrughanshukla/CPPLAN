#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int* b = &a;
    int** c = &b;
    // & ---> (Adress of operator)
    cout<< "The adress of a is "<<&a<<endl;
    cout<< "The adress of a is "<<b<<endl;
    // * ---> (value at) Defrefrence operator
    cout<< "The value at adress b is "<<*b<<endl;
    cout<< "The adress of b is "<<c<<endl;
    cout<< "The valeu at adress c is "<<*c<<endl;
    cout<< "The valeu at (value at adress (c)) is "<<**c<<endl;
    
    return 0;
}