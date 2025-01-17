/*
Write a C++ program to demonstrate the inheritance in object oriented programming (oops) by
taking the value of private variable 10, protected variable 20 and public variable 30, code
should print the values of all variables.
*/
#include<iostream>
using namespace std;
class Public{
    public:
    int pub;
    private:
    int pri;
    protected:
    int prot;

    public:
    void setValue(int val){
        pri = val;
    }
    int getValue(){
        return pri;
    }
};
class Prot: public Public{
public:
void setValue(int val){
        prot = val;
    }
    int getValue(){
        return prot;
    }
};

int main(){
Public p1;
p1.pub = 30;
p1.setValue(10);
Prot p2;
p2.setValue(20);

cout<< "The value of public member pub is "<< p1.pub<< " The value of private member pri is "<< p1.getValue() <<" The value of protected member prot is "<< p2.getValue() <<endl;
    return 0;
}
// // q2 easee.