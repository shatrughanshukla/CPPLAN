// // Abstract classes and pure virtual function.
#include<iostream>
using namespace std;

// class pokemon {
//     int height, weight;
//     public:
//     virtual void attack() = 0;
//     /*
//     A pure virtual function is a function that has no implementation in the abstract class but must be implemented by any derived class.
//     It is declared by assigning = 0 to the virtual function in the base class. 
//     */
// };

// class pikachu : public pokemon
// {
//     public:
//     void attack()
//     {
//         cout << "Thunderbolt"<<endl;
//     }
// };

// int main()
// {
// pokemon* p1;
// pikachu p2;
// p1 = &p2;

// // p1.attack(); can't real objects.
// p1->attack(); // // We can create pointer references of our abstract class that is having pure virtual function, but not able to create real objects.
// p2.attack();

//     return 0;
// }

// // Using Members of an Abstract Class :

class Pokemon {
    protected:
    int health;

    public:

    Pokemon(int hp) : health(hp) {} // // Initializer List:
// Pokemon(int hp) : health(hp) {} is a shorthand way to initialize data members directly with the constructor’s parameters.
// In the Pikachu class, which inherits from Pokemon, the constructor Pikachu(int hp) : Pokemon(hp) {} calls the Pokemon constructor and passes the hp parameter to initialize health in the base Pokemon class.
// This setup ensures that each Pikachu object has a specific health value upon creation.



    virtual void attack() = 0; // Pure virtual function
    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

class Pikachu : public Pokemon {
    public:
    Pikachu(int hp) : Pokemon(hp) {}
    void attack() override {
        cout << "Thunderbolt" << endl;
    }
};

int main() {
    Pikachu p(100);
    p.attack();
    p.displayHealth(); // Accessing a non-pure function from the abstract base class
    return 0;
}