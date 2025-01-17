// #include<iostream>
// using namespace std;
// class Grandparent
// {
//     public:
//     void print()
//     {
//         cout << "pika pika";
//     }
// };
//     class mother : public Grandparent
//     {};
//     class father : public Grandparent
//     {};
//     class child : public mother, public father
//     {};

// int main()
// {
//     child c;
//     c.print();
// }

// // output : error: request for member ‘print’ is ambiguous

/* A virtual base class in C++ is a concept used in inheritance to avoid multiple "copies" of a base class when multiple inheritance is involved.
It is especially useful when using diamond inheritance (or virtual inheritance) to prevent ambiguity and redundancy.

By declaring Grandparent as a virtual base class in mother and father (class mother : virtual public Grandparent), we ensure that only one instance of Grandparent is shared among all derived classes.
*/

#include<iostream>
using namespace std;
class Grandparent
{
    public:
    void print()
    {
        cout << "pika pika" << endl;
    }
};
    class mother : virtual public Grandparent
    {};
    class father : virtual public Grandparent
    {};
    class child : mother, public father
    {};

int main()
{
    child c;
    c.print();
    return 0;
}
