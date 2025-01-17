// // The programs written till now implements sequence structure, and this if-else program implements selection structure.
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
int age ;
// cout << "Marriage Test"<<endl;
cout << "What's your age?\n";
cin >> age;
// // // selection control structure: if- else-if else ladder
// if (age < 18 && age > 0)
// {
//     cout << "You're not eligible for marriage\n";
// }
// else if (age == 18)
// {
//     cout << "Go to your mom kiddo\n";
// }
// else if (age < 1)
// {
//     cout << "First come out pervert\n";
// }

// else{
//     cout << "Can I bring the protectioin tonight?\n";
// }

switch (age)
{
case 18:
    cout << "you are 18"<<endl;
    break;
case 22:
    cout << "you are 22"<<endl;
    break;
case 2:
    cout << "you are 18"<<endl;
    break;

default:
cout << "No special cases"<<endl; 
    break;
}

cout << "Done with switch cases"<<endl;
    return 0;
}