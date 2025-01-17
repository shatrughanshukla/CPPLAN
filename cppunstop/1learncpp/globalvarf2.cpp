#include<iostream>
using namespace std;
extern int i; // declaration of the global variable from globalvarf1.cpp
void modify(){
    i += 500;
}
/*
Compilation :
g++ file1.cpp file2.cpp -o output
Output :
./ output

Key Points :
Use of extern: The extern keyword is used to declare a global variable that is defined in another file. This allows you to share data between files while avoiding redefinition errors.

No Main in file2.cpp: Even though file2.cpp does not have a main() function, it still plays a crucial role in the program. The change() function modifies the global variable, and its effect is seen in the main() function of file1.cpp.

Maintaining State Across Files: This pattern is useful for maintaining state or configuration settings across different modules of a program.
*/