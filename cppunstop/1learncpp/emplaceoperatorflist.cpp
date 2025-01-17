// // diff between push_front and emplace_front.
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string n, int a) : name(n), age(a) {
        cout << "Person created: " << name << ", " << age << endl;
    }
};

int main() {
    forward_list<Person> people;

    // Using push_front (requires creating the object first)
    Person p("Alice", 30);   // Step 1: Create the object
    people.push_front(p);     // Step 2: Push to the list

    // Using emplace_front (constructs the object directly in the list)
    people.emplace_front("Bob", 25);  // Directly adds "Bob" to the list

    return 0;
}
