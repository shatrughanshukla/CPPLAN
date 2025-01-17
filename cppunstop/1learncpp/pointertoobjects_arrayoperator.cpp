#include<iostream>
using namespace std;
class Complex
{
    int x, y;
    public:

    // void setdata(int a, int b) : x(a) , y(b)
    // Complex setdata(int a, int b) : x(a) , y(b)
    /*
    The correct way to initialize member variables within a function is to use the assignment statements.
    The member initializer list syntax (: x(a), y(b)) can only be used in constructors, not in regular member functions.
    */
    // // Complex(int a, int b) : x(a) , y(b)  correct
    void setdata(int a, int b)
    {
        x = a;
        y = b;
    }
    void getdata()
    {
        cout << " The real part is : " << x << endl;
        cout << " The imaginary part is : " << y << endl;
    }

};
int main()
{
    Complex* ptr = new Complex;
    (*ptr).getdata();
    (*ptr).setdata(23, 565);
    (*ptr).getdata();

    ptr->setdata(34, 56);
    ptr->getdata();

    // // Array of objects
    Complex* ptr1 = new Complex[4];
    ptr1 -> setdata(56, 76);
    ptr1 -> getdata();
    return 0;
}