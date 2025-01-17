#include<iostream>
using namespace std;

class parent
{
    int x;
    public:
    parent(int a) // 1st cons
    {
        x = a;
        cout<<" The value of x is "<< x <<" parent class constructor "<<endl;
    }
    ~parent() // 3rd des
    {
        cout<<"parent class destructor "<<endl;
    }
};
class child: public parent
{
    int y;
    public:
    child(int b): parent(b) // 2nd cons
    {
        y = b;
        cout<<" The value of y is "<< y <<" child class constructor "<<endl;
    }
    ~child() // 2nd des
    {
        cout<<"child class destructor "<<endl;
    }
};
class grandchild : public child
{
    int z;
    public: 
    grandchild(int c) : child(c) // 3rd cons 
    {
        z = c;cout<<" The value of z is "<<  z<<" grandchild class constructor "<<endl;
    }
    ~grandchild() // 1st des
    {
        cout<<"grandchild class destructor "<<endl;
    }
};

int main()
{
    // grandchild g1;
    grandchild g1(20);
    /*
    automatically executes all grandchild, child and parent class constructor and destructors because of inheritance.
    */
    return 0;
}