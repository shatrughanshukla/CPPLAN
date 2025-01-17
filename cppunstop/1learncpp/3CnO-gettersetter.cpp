#include<iostream>
#include<string.h>
using namespace std;
// // int i = 1000;  // // global variable, can be accessed from other files using extern, e.g. open globalvar.cpp .
static int i = 0; // // global static variable, restricted to this file.
class student{
    private:
    int rollNo;
    char name[20];

    public:
    
    void setRollNO(){
    rollNo = ++i;
    }
    // void setRollNO(/*int roll*/){ // // when you want to take input from user.
    // //rollNo = roll;
    // cin>>rollNo;
    // }

    int getRollNO(){
        return rollNo;
    }

    void setName(char *nme){
        strcpy(name, nme);
    }
/*
nme points to the first character of the string passed in (e.g., the first character of temp). Then, the strcpy(name, nme) function copies the contents of the string that nme points to (the entire string) into the name array.
Since arrays in C/C++ do not have direct assignment like name = nme, we need to use strcpy to copy the string.

With the help of the pointer nme, strcpy moves through each character's address one by one and copies the value at that address (the character) into the destination array. It keeps doing this until it encounters the null terminator (\0), which signals the end of the

How strcpy Works Internally:
cpp
Copy code
"while ((*dest++ = *src++)); // Internal behavior of strcpy
src is the source pointer (nme in your case).
dest is the destination pointer (name in your case).
*src gives the value (the character) at the current pointer.
*dest = *src copies the character.
src++ and dest++ move both pointers to the next address (next character)".

*/
    char *getName(){
        return name;
    }

/*
Dereferencing with getName():
The getName() function returns a pointer to the name array. Since name is an array, and arrays in C/C++ are treated as pointers to their first elements, returning name (which is the same as returning &name[0]) gives the address of the first character in the array.
When you dereference getName() (i.e., use cout << s1.getName()), the entire string is printed, because C++ treats char* as a string and prints all the characters until it encounters the null terminator (\0).
*/

};

int main(){
    student s1,s2;
    s1.setRollNO();
    s2.setRollNO();
    // s1.setRollNO(); // when u're assigning the value inside the code.
    // s2.setRollNO();

    // s1.setRollNO(); // when u're taking the value from user.
    // s2.setRollNO();

    char temp[20];
    cout<< "Enter the name of student 1:"<<endl;
    cin >> temp;
    s1.setName(temp);

    cout << "Enter the name of student 2:"<<endl;
    cin >> temp;
    s2.setName(temp);

/*
Why temp is needed:
temp is used to temporarily store the input value for the student’s name. Here's why it's necessary:

Input Handling: In the main function, cin >> temp is used to accept input from the user. This input is stored in the temporary array temp.
After the input is stored in temp, you pass it to setName(temp), which uses the temp array as an argument.
Inside the setter setName, you call strcpy(name, nme), which copies the contents of temp (the user input) into the name array inside the student object.

*/

    cout<< "The name of student 1 is : "<<s1.getName()<<endl;
    cout<< "The rollNO of student 1 is : "<<s1.getRollNO()<<endl;
    cout<< "The name of student 2 is : "<<s2.getName()<<endl;
    cout<< "The rollNO of student 2 is : "<<s2.getRollNO()<<endl;
    return 0;
}
/*
void setName(char *nme){
        strcpy(name, nme);
    }

pointers and dereferene :
char *nme - we're creating a pointer which can store the address of a string and at the sme time when we write like this it's dereferncing the first element which is passed to nme through temp.
This gives the first character and in strcpy it moves with first element adress given to the pointer.

Pointer and Dereferencing Explained
Pointer Declaration (char *nme):

When you declare char *nme, you're creating a pointer variable named nme that can store the address of a char type variable. In the context of strings, this pointer can point to the first character of a character array (or string).
For example, if you have a string char temp[] = "John";, then nme can be assigned temp, and it will point to the first character 'J'.
Dereferencing (*nme):

Dereferencing a pointer means accessing the value that the pointer is pointing to. When you use *nme, you are getting the character value at the memory address that nme holds.
For example, if nme points to the string "John", then *nme would give you the first character 'J'.
How They Work Together
Functionality:
When you pass a string to the function setName(char *nme), nme receives the address of the first character of the string. Inside the function, you can manipulate this string by accessing its characters using pointer arithmetic (e.g., nme[0], nme[1], etc.) or by dereferencing the pointer.
When you use strcpy(name, nme), the strcpy function needs to start copying from the address stored in nme. It doesn't need to dereference nme because it understands that it is receiving a pointer.
Why You Can't Use char nme
If you declare void setName(char nme), you are only accepting a single character, not a string. This means:
nme can hold only one character, and when you try to copy a string with strcpy, it will generate an error because strcpy expects a pointer to the first character of a string (i.e., char *), not a single character.

*/
