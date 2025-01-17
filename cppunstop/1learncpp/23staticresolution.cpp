// // exception static resolution.
#include<iostream>
using namespace std;

class pokemon
{
    private:
    int Height, Weight, Attack;

    public:
    // to not to do static resolutiom / force late binding run time.
    virtual void attack()
    {
        cout << "Pokemon attacked"<<endl;
    }
    // // stating resolution / early binding / compile time poly
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

    void defend()
    {
        cout << "Pokemon defended and ran"<<endl;
    }
};

int main()
{
pokemon* p1;
pikachu Pikachu;
p1 = &Pikachu; 

p1->attack();
p1->defend();

    return 0;
}
/*
The approach should be, in cpp address has the priority, so here p1 has stored the address of Pikachu so,
p1->attack();
p1->defend(); should have called the function signature of pikachu class but that doesn't happens and funcn sign of pokemon class is called.

// // This exception is because of // STATIC RESOLUTION !
*/