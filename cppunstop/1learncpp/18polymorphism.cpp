// // operator overloading
// // Binary
#include<iostream>
using namespace std;

class complex
{
    int real, img;
    public:

    void getdata()
    {
        cin >> real >> img;
    }

    void display()
    {
        if (img < 0)
        {
            cout << real << " " << img << "j" << endl;
        }
        else
            cout << real << "+" << img << "j" << endl;
    }

    complex operator +(complex tempobj)
    {
        cout << "Called by object " << real << endl;
        cout << "passed object " << tempobj.real << endl;
        /*
        tempobj is the object passed as an argument to the operator function.
        When you write obj1 + obj2, tempobj represents obj2, while obj1 is the object on which the operator+ function is called.
        
        Remember in unary operator overloading, we used one object to be added to itself and used c++;, in this we c is the object for which operator+ is called.
        similarly here, obj1 is the object for which operator+ function is called, and onj 2 is the object which is passed as an argument.

        observation -- 
        Like in unary operator overloading, for c++; we used void operator ++(int), we've to pass a parameter then c++ form was able to use,
        similarly here for binary we write class operator +(class tempobj) and use obj1 as object called and obj2 as obj passed,
        we write class so that we can pass the value which is assigned under the class type of variable temp.result.
        we create tempresult as class type becaue it's storing class type variables.
        
        */
        complex tempresult;
        tempresult.real = real + tempobj.real;
        tempresult.img = img + tempobj.img;

        return tempresult;
    } 
};

int main()
{
complex obj1, obj2, result;
obj1.getdata();
obj2.getdata();

result = obj1 + obj2;
result.display();
    return 0;
}