#include<iostream>
#include<iomanip>
using namespace std;

class Demo
{
    public:
    int i;
    float f;

    Demo(int val1, float val2)
    {
        i = val1;
        f = val2;
        cout << "constructor is called !" << endl;
    }
};

int main()
{
// // parameterised constructor.
Demo demo1(20, 31.000f); // // using f makes it clear that the literal is float, which can help prevent potential issues in both type safety and performance.
Demo demo2(220, 341.0f);

cout << "demo1.i = " << demo1.i << " & " << " demo1.f = " << demo1.f << endl;
cout << "demo2.i = " << demo2.i << " & " << " demo2.f = " << demo2.f << endl;
cout << "demo2.i = " << demo2.i << " & " << " demo2.f = " << fixed << setprecision(1)<< demo2.f<< endl;
    return 0;
}

// // question given 5.000000
// //                5.0 
// // set and fixed precision.
// // error when use setprecision without fixed.