#include<iostream>
using namespace std;
int fib(int n){
if (n<2)
{
    return 1;
}
return fib(n-2) + fib(n-1);
}

int factorial(int n){
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n-1);
}
int main(){
    int x;
    cout << "Enter the value of x"<<endl;
    cin >> x;
    cout << "The factorial of x is : " <<factorial(x)<<endl;

    int a;
    cout << "Enter the value of a : " <<endl;
    cin >> a;
    cout << "The term in fibonacci sequence at position "<<a<<" is "<<fib(a)<<endl;
    return 0;
}