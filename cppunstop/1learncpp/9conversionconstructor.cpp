#include<iostream>
using namespace std;

class conversion
{
    int x;
    int y;

    public:

    /*
            // // myth - only one argument is allowed for conversion constructor.
            // // actual - we can take more than one argument, but 
            // // there should be either 0 or at max 1 argument non intialised, and the first parameter shoudld be made non intialised.
    */
    // allowed ->
    // conversion(int a)
    // conversion(int a = 0, int b = 0)
    // conversion(int a = 0)

    // // not allowed -> 
    // conversion(int a = 0, int b)
    // conversion(int a, int b)

    conversion(int a, int b = 0)
    {
        x = a;
        // y = 4000;
        y = b;
    }

    void display()
    { 
        cout<< "The value of x is : "<<x<< " & "<< "The value of y is : "<<y<<endl;
    }

}; 

int main()
{
    // conversion c1(); --> not allowed when intialised a parametric constructor.
    
    // // Basic parameterised constructor with one parameter passed.

    conversion c1(10);
    // conversion c1(10); // Basic parameterised constructor with two parameter passed.
    c1.display();

    // // implicit calling(intialization) using assignment operator // implicit -not directly doing. // not the correct way of calling constructor this is called implicit call using assignment operator

    c1 = 100; // // conversion constructor
    c1.display();

    c1 = {100, 20}; // // can be implicitly intialised like arrays to pass 2 arguments.
    /*
    c1 = {100, 200}; - > implicit initialization - > aggregate initialization,  Aggregate Initialization traditionally refers to initializing simple data structures like arrays or structs directly with values.
    Initializer List (Brace Initialization): The use of {100, 200} is an initializer list.
    This form of initialization is typically associated with aggregate types like arrays and structs
    */
    c1.display();
    return 0;
}
/*
In programming, the term "implicitly" refers to actions that happen automatically or without direct instruction by the programmer.
It does not mean "forcefully." Instead, it means that the compiler performs the action on its own, based on the rules of the language, without requiring the programmer to explicitly state it.

*/

/*
The setters and getters can be replaced with the help of constructors.

Summary:
Constructor initializes private variables at the time of object creation, removing the need for setters.
Display function acts like a getter, retrieving and displaying the values of the private variables.
The constructor does the work of setting initial values, so no separate setter is required for this functionality.
*/

/*

Function Overloading:
Function overloading occurs when multiple functions share the same name but have different parameter types or counts. In your code, the constructor is overloaded.

Constructor Overloading: The constructor conversion is overloaded because it can accept different numbers of arguments:
conversion(int a, int b = 0) is overloaded to allow:
conversion c1(10); (one argument with b defaulting to 0)
conversion c1(10, 20); (two arguments where both a and b are specified).
Function Overriding:
Function overriding happens in the context of inheritance, where a derived class provides its own implementation of a base class's virtual function. Since your code does not involve any inheritance or base class, there is no function overriding.

Conclusion:
Constructor Overloading: The constructor is overloaded at two potential places:
One argument (conversion c1(10);)
Two arguments (conversion c1(10, 20);)
Function Overriding: Not present in the code as there is no inheritance.

*/