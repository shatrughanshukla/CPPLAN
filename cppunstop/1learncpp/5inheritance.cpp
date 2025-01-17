#include<iostream>
using namespace std;
class A{
int z; // // by default it's private

public:
int x;

protected:
int y;

// // x, y and z are accessible within the class.
};

class B:public A{
// // x is inherited and stays public in child.
// // y is inherited and stays protected in child.
// // z is not inherited and not accessible.
};

class C:protected A{
// protected:
// int x;   // // it is inherited in this form.

// x is inherited but becomes protected.
// y is inherited and stays protected.
// z is not inherited.
};

class D:private A{
// // x is inherited but becomes private.
// // y is inherited but becomes private.
// // z is not inherited.
};

int main(){

    return 0;
}