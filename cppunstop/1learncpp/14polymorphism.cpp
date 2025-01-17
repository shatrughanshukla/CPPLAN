// // Function overloading.
#include<iostream>
using namespace std;

class Prepinsta
{
    int x,y,z;
    float a,b;
    double d,e;

    public:

    void sum()
    {
        cout<<"Dandadan"<<endl;;
    }

    void sum(int a, int b)
    {
        x = a;
        y = b;
        cout << "The sum is : " << x + y <<endl;
        cout<<"int"<<endl;
    }

    void sum(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
        cout << "The sum is : " << x + y + z << endl;
        cout<<"int"<<endl;
    }

    void sum(float x, float y)
    {
        a = x;
        b = y;
        cout << "The sum is : " << a + b << endl;
        cout<<"float"<<endl;
    }

    void sum(double x, double y)
    {
        d = x;
        e = y;
        cout << "The sum is : " << a + b << endl;
        cout<<"Double"<<endl;
    }

};

int main()
{
    Prepinsta obj;

    obj.sum();
    obj.sum(12.32424f, 34.543434f); // // if we don't use f then it's calling double as it's more precise, we should use f for clearity.
    obj.sum(12, 14);
    obj.sum(13, 56, 45);
    obj.sum(23.32424423424, 45.345535535);

    return 0;
}