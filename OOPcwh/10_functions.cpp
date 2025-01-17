#include<iostream>
using namespace std;
// //int sum(int a, int b); accepatable. // This is functioin prototype
// //int sum(int a, b); --> not acceptable.
int sum(int, int); // acceptable
void g(void); // acceptable
// void g(); // acceptable

int main(){
    int  num1, num2;  // num 1 and num 2 are actual parameters.
    cout << "The value of num 1 is : "<<endl;
    cin>> num1;
    cout << "The value of num 2 is : "<<endl;
    cin>> num2;
    cout<<"The sum is "<<sum(num1, num2)<<endl;
    g();
    return 0;
}
int sum(int a, int b){
    // // formal parameters a and b will be taking value from actual parameter num 1 and num 2.
    int c = a+b;
    return c;
    
}
void g(){
    cout << "Hello rishav, good morning";
}