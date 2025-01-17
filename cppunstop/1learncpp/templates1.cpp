// #include<iostream>
// using namespace std;

// class templates
// {
//     public:
//     int* arr;
//     int size;
//     templates (int m)
//     {
//         size = m;
//         arr = new int[size];
//     }
    
//     int dotProduct(templates &v) {
//         int d = 0;
//         for (int i = 0; i < size; i++)
//         {
//             d += this->arr[i] * v.arr[i];
//         }
//         return d;
//     }
// };

// int main()
// {
//     templates t1(3);
//     t1.arr[0] = 4;
//     t1.arr[1] = 3;
//     t1.arr[2] = 1;
//     templates t2(3);
//     t2.arr[0] = 1;
//     t2.arr[1] = 0;
//     t2.arr[2] = 1;

//     int a = t1.dotProduct(t2);
//     cout << a << endl;
//     return 0;
// }

/*
In the main function, the dotProduct function is called on the t1 object with t2 as an argument, using the syntax:

cpp
Copy code
int a = t1.dotProduct(t2);
This line does the following:

Object Method Call: t1.dotProduct(t2) means the dotProduct method is being called on the t1 object. Since dotProduct is a member function of the templates class, this function will have access to t1’s data (like t1.arr and t1.size) through the implicit pointer this.

Passing t2 as an Argument:

The dotProduct function takes a reference to another templates object as a parameter: templates &v.
When t2 is passed as an argument, it is bound to this parameter v in dotProduct.
This allows dotProduct to access t2’s arr and size data members via v.arr and v.size.
Execution of dotProduct:

Inside dotProduct, the function computes the dot product of t1 (the object calling the method) and t2 (passed as v).
this->arr[i] refers to t1's elements, while v.arr[i] refers to t2's elements.
Returning and Storing the Result:

The dotProduct function returns the calculated result (d), which represents the dot product of the two vectors.
This result is stored in the variable a in main.
Output:

Finally, cout << a; prints the result of the dot product.
So, in summary, t1.dotProduct(t2); calls the dotProduct function on t1, using t2 as the other vector to multiply element-by-element, and accumulates the result in a, which is then printed.
*/

#include<iostream>
using namespace std;
template <class T>
class templates
{
    public:
    T* arr;
    int size;

    templates(int m)
    {
        size = m;
        arr = new T[size];
    }
T dotProduct(templates &v)
{
    T d = 0;
    for (int i = 0; i < size; i++)
    {
        d += this->arr[i]*v.arr[i];
    }

    return d;

}

};


int main()
{
    templates <int> t1(4); 
    t1.arr[0] =  5;
    t1.arr[1] =  8;
    t1.arr[2] =  2;
    t1.arr[3] =  9;
    templates <int> t2(4); 
    t2.arr[0] =  8;
    t2.arr[1] =  2;
    t2.arr[2] =  5;
    t2.arr[3] =  9;

    int d = t1.dotProduct(t2);
    cout << d << endl;
    templates <float> t3(4); 
    t3.arr[0] =  6.6;
    t3.arr[1] =  8.8;
    t3.arr[2] =  2.00;
    t3.arr[3] =  0.01;
    templates <float> t4(4); 
    t4.arr[0] =  8.4;
    t4.arr[1] =  2.7;
    t4.arr[2] =  0;
    t4.arr[3] =  4.9;

    float e = t3.dotProduct(t4);
    cout << e << endl;
    return 0;
}