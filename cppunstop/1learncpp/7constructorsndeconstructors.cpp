// // I'ev formatted this file to learn how the clean format looks like.
#include <iostream>
using namespace std;

class cons
{
    int i;

public: // // general constructor.

    cons(); // // Assigning constructor outside of class.
    // cons()
    // {
    //     i = 0;
    //     cout << "The constructor is called !" << endl;
    // }

    ~cons();

    int geti()
    {
        return i;
    }
};

cons ::cons()
{
    i = 0;
    cout << "The constructor is called !" << endl;
}

cons ::~cons() // // Destructors are essential for resource management and are called when objects go out of scope or are deleted. They ensure the program cleans up resources efficiently, avoiding memory leaks and other issues related to resource allocation.
{
    cout << "Desructor is called !" << endl;
}

int main()
{
    cout << "Before calling constructor" << endl;
    // // memory is created.
    cons c1;
    cout << "After calling constructor" << endl;
    cout << "The value of i is : " << c1.geti() << endl;

    int x = 1;
    if (x)
    {
        cons c2; // // constructor is created.
        cout << "constructor is called for c2." << endl;
    } // // detructor is called
    cout << "Above destructuor is called beacuse it goes out of scope !" << endl;

    return 0; // Destructor will be called automatically at the end of the program
}
/*

Why Do We Need Constructors?
Constructors in C++ are special member functions that are automatically called when an object of a class is created. Their primary purpose is to initialize objects to a valid state. Constructors help set initial values for member variables, allocate resources, or perform other setup tasks that an object needs to function correctly.

When to Use Constructors?

Initializing Variables: If an object requires specific initial values for its data members.
Resource Allocation: If the object manages external resources like files, memory, or network connections, constructors can allocate and prepare these resources.
Preventing Uninitialized Data: They ensure that objects don’t start with garbage values by providing meaningful default or user-defined initial values.

Types of Constructors:
Default Constructor: A constructor with no parameters.
Parameterized Constructor: A constructor that takes arguments to initialize an object with specific values.
Copy Constructor: Initializes a new object as a copy of an existing object.

*/