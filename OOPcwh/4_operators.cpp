#include<iostream>
using namespace std;

int main() {
int m=4, b=5;
cout << "The Value of m++ is " <<m++<<endl;  // 1st executes then increases the value by 1
cout << "The Value of m-- is " <<m--<<endl;  // 1st executes then decreases the value by 1
cout << "The Value of ++m is " <<++m<<endl;  // 1st increases the value then increases
cout << "The Value of --m is " <<--m<<endl;  // 1st decreases the value then increases

    return 0;
}