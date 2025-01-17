// // operator overloading
// complex
#include<iostream>
using namespace std;
class complex 
{
    int real, img;
    public:
    void print()
    {
        if (img < 0)
        {
            cout << real << " " << img << "j"<< endl;
        }
        else
        {
            cout << real << "+" << img << "j" <<endl;
        }      
    }

    void getdata()
    {
        cin >> real >> img;
    }

    // void operator ++()
    // {
    //     ++real; // it can be real ++, print is after the }, i.e. doesn't matter can use both.                
    //     ++img;  // // if have used cout << ++real then, let us consider the argument passed is 4 then 5 will print, and if've used cout << real ++ then, 4 will print.
    //}
    void operator ++(int) // // for using c++, we've to pass a parameter, // same goes for string, we pass char parameter for string.
    {
        ++real;
        ++img;
    }


};
int main()
{
complex c;
c.getdata();
cout << "Before"<<endl;
c.print();

c++;
cout<<"MID to show c++"<<endl;
c.print();

// ++c;
// cout << "After"<<endl;
// c.print();
    return 0;
}