#include<iostream>
using namespace std;
int i = 1000; // global variable.
void enter(){
    cout << "Enter the value of Global variable i"<<endl;
    cin >> i;
}
void modify();
void display(){
    cout<<"The value you entered of globalvariable is : "<< i<<endl;
}
int main(){
    enter();
    display();
    modify();
    display();
    return 0;
}
// Booyahhhh !!!!!!!
