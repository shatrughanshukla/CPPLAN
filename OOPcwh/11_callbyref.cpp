#include<iostream>
using namespace std;
// // This will not swap a and b because x and y are giving there values void isn't returning anything here and x and y values are actual..
void swap(int a, int b){  // temp a b 
    int temp = a;         // 4    4 5
    a = b;                // 4    5 5
    b = temp;             // 4    5 4
}
// // call by reference using pointers.
// // will swap the values because here we play with the addresses of the actual parameters.
// void swappointer(int* a , int*b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swapreferencevar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// return ref variable....

int & swapreturnreferencevar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return a; //this returns the value of a.
}

int main(){
    int x = 4, y = 5;  // actual values
    cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    swap(x,y); // This will not swap x and y.
    cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl;
    // swappointer(&x, &y); // this will swap x and y.
    cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl;
    swapreferencevar(x, y);
    cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl; // this gives 4 and 5 cause swap pointer has aready swapped the xand y this re swappes the values.
    swapreturnreferencevar(x, y) = 234; // swappes and returns the parameter mentioned, can proceed without assigning.
    cout << "The value of x is "<<x<<" and the value of y is "<<y<<endl;
    return 0;
}