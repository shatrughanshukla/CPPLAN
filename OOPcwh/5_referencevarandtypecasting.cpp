#include<iostream>
using namespace std;

int c = 45;
int main(){
int a, b, c;
cout << "The value of a is "<<endl;
cin >> a;
cout << "The value of b is "<<endl;
cin >> b;
c = a+b;
cout << "The value of a+b is "<<c<<endl;
cout << "The value of c is "<<::c<<endl; // // :: scope reolution operator.



// // sizeof - the sizeof operator is used to determine the size (in bytes) of a data type, variable, or object in memory.
// // **********************************Reference Varialbles*************************************// //
float x = 323;
float & y = x;
cout<<x<<endl;
cout<<y<<endl;
// // **********************************Type Casting*************************************// //
int m = 56;
float n = 45.544;
cout<<"The value of m is "<<(float)m<<endl;
cout<<"The value of m is "<<float(m)<<endl;
cout<<"The value of n is "<<(float)n<<endl;
cout<<"The value of m is "<<float(n)<<endl;
cout<<"The value of m is "<<int(n)<<endl;
int p = int(n);
cout<<"The value of the expression is "<<m+n<<endl;
cout<<"The value of the expression is "<<m+int(n)<<endl;
cout<<"The value of the expression is "<<m+(int)n<<endl;
cout<<"The value of the expression is "<<m+p<<endl;

    return 0;
}