// // Member Function Templates & Overloading Template Functions in C++ 

// Code Snippet 1: Writing function inside the class
// #include<iostream>
// using namespace std;
// template<class T>
// class Harry
// {
//     public:
//     T data;
//     Harry(T t)
//     {
//         data = t;
//     }

//     void display()
//     {
//         cout << data << endl;
//     }

// };

// int main()
// {
//     Harry <float> f(34.56);
//     f.display();
// }

// Code Snippet 2: Writing function outside the class

// #include<iostream>
// using namespace std;
// template<class T>
// class Harry
// {
//     public:
//     T data;
//     Harry(T t)
//     {
//         data = t;
//     }

//     void display();
    
// };

// template <class T>
// void Harry<T> :: display() // // return type void h, The Harry<T> part is required to indicate that this function definition belongs to the specific instantiation of the Harry template class, :: display() Indicates that display() is a member function of the Harry<T> class.
// {
//         cout << data << endl;
// }

// int main()
// {
//     Harry <float> f(34.56);
//     f.display();
// }


// // Code Snippet 3: Overloading the template function
#include<iostream>
using namespace std;

void func(int a)
{
    cout << "I'm first func()" << endl;
}

template <class T>
void func(T a)
{
    cout << "I'm templatised func()" << endl;
}

int main()
{
    func(2);  // //Exact match takes the highest priority
    func(2.0);
    return 0;
}