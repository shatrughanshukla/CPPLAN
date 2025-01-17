// // Function Templates & Function Templates with Parameters

// Suppose we want to have a function which calculates the average of two integers.
// So, this must be very easy for you to formulate. Look for the snippet below. Suppose we want to have a function which calculates the average of two integers.
// So, this must be very easy for you to formulate. Look for the snippet below. 

// #include<iostream>
// using namespace std;
 
// float funcAverage(int a, int b){
//     float avg= (a+b)/2.0; 
//     return avg;
// }
// int main(){
//     float a;
//     a = funcAverage(5,2);
//     cout << "The average of these numbers is" << a << endl;
//     return 0;
// }


#include<iostream>
using namespace std;
template < class T1, class T2 >
float funcAvg(T1 a, T2 b)
{
    float avg = (a+b)/2.0;
    return avg;
}

template <class T>
void swapp (T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    float a;
    a = funcAvg(3, 5.9);
    cout << "The average of these numbers is " << a << endl;
    int x, y;
    cout << "Enter the value of x and y" <<endl;
    cin >> x >> y;
    swapp(x, y);
    cout << x << " " << y << endl;
}