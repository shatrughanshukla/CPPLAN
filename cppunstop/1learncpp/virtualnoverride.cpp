#include<iostream>
using namespace std;

// Base class
class Base {
public:
    virtual void display() {  // Virtual function in base class
        cout << "Base class display function" << endl;
    }
    virtual ~Base() {}  // Virtual destructor
};

// Derived class
class Derived : public Base {
public:
    // Override base class function
    void display() override {  // `override` ensures we're overriding a virtual function
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base* ptr = new Derived();  // Polymorphism: Base pointer pointing to Derived object
    ptr->display();  // Calls Derived class display function due to virtual function
    
    delete ptr;  // Proper cleanup, calling virtual destructor
    return 0;
}
/*
Virtual functions can be accessed using pointers, references, or direct objects.
*/