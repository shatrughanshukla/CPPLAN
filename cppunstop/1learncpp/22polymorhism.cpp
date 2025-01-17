#include<iostream>
using namespace std;

class pokemon
{
    private:
    int Height, Weight, Attack;

    public:
    void attack()
    {
        cout << "Pokemon attacked"<<endl;
    }

    void defend()
    {
        cout << "Pokemon defended"<<endl;
    }

};
class pikachu : public pokemon
{
    public:
    void attack()
    {
        cout << "Pikachu attacked thunderbolt"<<endl;
    }

    // void defend()
    // {
    //     cout << "Pikachu defended and ran"<<endl;
    // }
};

int main()
{
pikachu p1;
p1.attack();
p1.defend();

    return 0;
}

/*
If child has funcn signature then child funcn has higher priority, if not then parent have higher priority.

A function signature in C++ (and many programming languages) is the part of a function that defines its name, return type, and parameter types (including their order and count).
The signature is crucial for the compiler to distinguish between different functions, especially in cases of function overloading.

However, in C++ specifically, the return type is not part of the function's unique signature for the purposes of overloading.
This means you cannot have two functions with the same name and parameters but different return types.
*/