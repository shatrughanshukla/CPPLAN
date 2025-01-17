#include<iostream>
using namespace std;
class complex;
class calculator
{
    public:
    int add(int a, int b)
    {
    return (a+b);
    }

    // int sumrealcomplex(complex , complex )
    // {
    //     return (o1.a + o2.a);
    // }
    // // this will not work because here compliler don't know if a exidt or not  i.e. we'll define it here and will create it's function after the class declaring a.

    int sumrealcomplex(complex o1, complex o2);
    // // can also be written as int sumrealcomplex(complex , complex );
    int sumcompcomplex(complex o1, complex o2);
};

class complex 
{
    int a, b;
    public:
    // // // Individually declaring fnctions as friends, but when many fuctions has to declare to reduce time and increase efficiency we made friend class.
    // friend int calculator :: sumrealcomplex(complex o1, complex o2);
    // // // can also be written as friend int calculator :: sumrealcomplex(complex , complex );
    // friend int calculator :: sumcompcomplex(complex o1, complex o2);

    // Aliter: Declaring the entire calculator class as friend
    friend class calculator;

    void setnum(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void getnum()
    {
        cout << "The complex num is ; " << a << " + " << b <<"i" << endl; 
    }
};


int calculator :: sumrealcomplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
}

int calculator :: sumcompcomplex(complex o1, complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    complex c1, c2, sum;
    c1.setnum(23, 57);
    c1.getnum(); 
    c2.setnum(3, 34);
    c2.getnum(); 
    calculator c;
    int res = c.sumrealcomplex(c1, c2);
    cout << "The sum of real part of c1 and c2 is : " << res << endl; 
    int resc = c.sumcompcomplex(c1, c2);
    cout << "The sum of real part of c1 and c2 is : " << resc << endl; 
    return 0;
}