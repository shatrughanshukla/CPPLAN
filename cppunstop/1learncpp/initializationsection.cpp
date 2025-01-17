/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}

*/

#include<iostream>
using namespace std;

class Test
{
    int a, b;
    public:
    // // Test(int i, int j) : a(i) , b(j)
    // // Test(int i, int j) : b(j),  a(i + b)  // // The compiler throws an error because the data member “a” is being initialized first and the “b” is being initialized second so we have to assign the value to “a” data member first.
    Test(int i, int j) : a(i), b(a + j)

    {
        cout << "Initializer list assigned" << endl;
        cout << "The value of x is : " << a << endl;
        //cout << "The value of b is : " << b << endl;
        cout << "The value of x + y is : " << b << endl; // // the compiler not throws an error because the data member “a” is being initialized first and we are assigning the value to the data member “a” first.
    }
};

int main()
{
    int x , y;
    cout << "Enter the value of x and y" << endl;
    cin >> x >> y;
    Test(x, y);
}