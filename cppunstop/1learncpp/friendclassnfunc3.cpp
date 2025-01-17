#include<iostream>
using namespace std;

class y;

class x 
{
    int data;
    public:
    void setValue(int value){
        data = value;
    }
    friend void add(x , y);
};


class y 
{
    int num;
    public:
    void setValue(int value){
        num = value;
    }
    friend void add(x , y);
};

void add(x o1, y o2)
{
    cout << "summing data of x and y objects gives me " << o1.data + o2.num << endl;
}

int main()
{
    x a1;
    a1.setValue(34);

    y b1;
    b1.setValue(26);

    add(a1 , b1);
}