// shallow copy and deep copy concepts for integers.
#include<iostream>
using namespace std;

class prepinsta
{
    int* ptr;

    public:
    prepinsta(){}

    prepinsta(int x)
    {
        ptr = new int;
         // // ptr = &x; // // we didn't used & here, cause we're passing the value directly and it is getting stored in ptr.
        *ptr = x; 
    }

prepinsta(prepinsta &obj1) // //deep copy.. creating our own copy constructor.
{
    ptr = new int;
    *ptr = *obj1.ptr;  
}
    ~prepinsta()
    {
        delete ptr;
    }

    void printf()
    {
        cout<<*ptr<<endl;
    }

    void multiply(int num2)
    {
        *ptr = *ptr*num2;
    }
};

int main()
{
  prepinsta obj1(10);
  prepinsta obj2 = obj1;
  cout<<"Before multiplication"<<endl;
  obj1.printf();  
  obj2.printf(); 

  obj1.multiply(20); 
  cout<<"After multiplication"<<endl;
  obj1.printf();  
  obj2.printf(); 

    return 0;
}