// // operator overloading..
// // ::	.*	.	?: these operators can't be overloaded !!
#include<iostream>
using namespace std;
class Prepinsta
{
    int x = 0;
    int y = 0;
    int z = 69;

    public:

    void print()
    {
        cout << "The value of x is : " << x << " The value of y is : " << y << " The value of z is : " << z << endl; 
    }

void operator ++()
{
    x++;
    y--;
    z *= (z*69);
}

};

int main()
{
    Prepinsta p1;
    cout<<"Before ++"<<endl;
    p1.print();


    cout<<"after ++"<<endl;
    ++p1; // ++p1; is equivalent to p1.operator++();
    p1.print();

    return 0;
}
