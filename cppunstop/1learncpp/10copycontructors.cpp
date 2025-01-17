#include<iostream>
using namespace std;

class blopy
{
    int x;
    int y;

    public:
    // // parameterised constructor.
    blopy(int a, int b)
    {
        x = a;
        y = b;

        cout<< "The parameterised constructor is called"<<endl;
    }

    // default constructor 
    blopy()
    {
        cout << "default constructor is called"<<endl;
    }

    // // copy constructor.
    blopy(const blopy &p5){ // // as we're passing an object in argument we need to use pass by reference. 
        x = p5.x;
        y = p5.y;

        cout<< "copy constructor is called "<< endl;
    }

    int getx()
    {
        return x;
    }

    int gety()
    {
        return y;
    }

};

int main()
{
    // // parameterised constructor.
    blopy b1(23, 434);

    // // copy constructor.
    blopy b2(b1); // we'll pass the object and it will decide the values on it's with the b1 object.

    blopy b3 = b2; // // similar to blopy b3(b1);

    // // case when copy constructor isn't called --
    blopy b4;
    // assignment happening.
    b4 = b1; // // all the variables of b1 is getting copied to b4.

    cout<< "The value of b1.x is "<< b1.getx() << " & " << "The vale of b1.y is "<< b1.gety() << endl;
    cout<< "The value of b2.x is "<< b2.getx() << " & " << "The vale of b2.y is "<< b2.gety() << endl;
    cout<< "The value of b3.x is "<< b3.getx() << " & " << "The vale of b3.y is "<< b3.gety() << endl;
    cout<< "The value of b1.x is "<< b4.getx() << " & " << "The vale of b1.y is "<< b4.gety() << endl; // // all the value's are being printed but these are assignment values.

    return 0;
}

/* 
When you create constructor on your own then compiler doesn't create it's own vesion of constructor at all, and
we need to create the default constructor on our own if we're creating an object like b4 in this case.

// // uses of const 
const ensures that the original object remains unchanged when passed to the copy constructor.

Reference (&) ensures that the object is passed efficiently, without making a copy.

Combining const and reference (const &) allows copying of both const and non-const objects safely and efficiently.
*/