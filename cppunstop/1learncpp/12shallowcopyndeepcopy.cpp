#include<iostream>
#include<string.h>
using namespace std;

class diwali
{
    char *string;

    public:
    diwali()
    {
        cout<<"default constructor is called ";
    }

    diwali(const char *str)
    {
        string = new char[16];
        strcpy(string, str);

    }

    // // creating user defined copy constructor.

    diwali(const diwali &str)
    {
        string = new char[16];
        strcpy(string,str.string);

    }

    ~diwali()
    {
        delete[] string;
    }


    void print()
    {
        cout << string <<endl;
    }

    void concatenate(const char *str)
    {
        strcat(string, str);

    }
};

int main()
{
    diwali d1("Diwali");
    diwali d2 = d1;
    // diwali d2(d1);
    
    cout<< "Before concatenation"<<endl;

    d1.print();
    d2.print();

    cout<< "after concatenation"<<endl;

    d1.concatenate(" mela");
    d1.print();
    d2.print();
    // d2.concatenate(" mela");

}