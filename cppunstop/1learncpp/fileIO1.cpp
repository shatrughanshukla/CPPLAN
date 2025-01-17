/*
File I/O in C++: Reading and Writing Files
These are some useful classes for working with files in C++

fstreambase
ifstream --> derived from fstreambase
ofstream --> derived from fstreambase

In order to work with files in C++, you will have to open it. Primarily, there are 2 ways to open a file:

Using the constructor
Using the member function open() of the class
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string st1 = "I'll learn everything";
    string st2;


    // Opening files using constructor and writing it
    ofstream out ("fileIOsample1.txt");
    out << st1;
    out.close(); // Closing file after writing to avoid any issues
    
    // // opening files using constructor and writing it.
    ifstream in ("fileIOsample2.txt");
    // in >> st2;
    // cout << st2;
    // // only gives text until space occurs or on initialization of new line.
    getline(in , st2);
    cout << st2;
    in.close(); // Closing file after writing to avoid any issues


    return 0;
}