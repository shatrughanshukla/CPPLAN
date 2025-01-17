#include<iostream>
using namespace std;

class A
{
    int a;
    public:
    // void setdata(int a) // when not returning *this
    A & setdata(int a) // A & is the return type of setdata, which means it returns a reference to an object of class A.
    {
        // // a = a; // gives garbage value.
        this -> a = a; 
        return *this;
    } 

    void getdata()
    {
        cout << "The value of a is : " << a << endl;
    }
    // int getdata()
    // {
    //     return a;
    // }

};

int main()
{
    A a;
    a.setdata(26).getdata(); // In the main program by using a single object we have made a chain of the function calls. The main thing to note here is that the function “setData” is returning an object on which we have used the “getData” function. so we don’t need to call the function “getData” explicitly.

    // // a.getdata();
}