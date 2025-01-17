#include<iostream>
using namespace std;
class student
{
    int feet= 0, inches=0;
    public:
    void getdata(int f, int i)
    {
        if (f>=0 && (i>=0 && i<12))
        {
            feet = f;
            inches = i;
        }
        else 
        cout<<"Wrong height, default 0, 0 will be taken"<<endl;
        
    }
    bool operator >(student obj)  
/*
the bool return type lets operator > provide a true or false result, 
which allows if statements to directly compare student objects by height.
*/
    {
        if (feet > obj.feet)
        {
            return true;
        }
        if (inches > obj.inches)
        {
            return true;
        }

        return false;
        
    }

    bool operator ==(student obj)
    {
        if (feet == obj.feet && inches == obj.inches)
        {
            cout << "The heights are different" <<endl;
            cout << "== called"<<endl;
        }
        return false;
    }


};

int main()
{
student s1, s2;
s1.getdata(5,10);
s2.getdata(5,11);

if (s1 > s2)
{
    cout << "student 1 is taller " << endl; 
}
if (s2 > s1)
{
    cout << "student 2 is taller " << endl;
}
// // else
// // cout << "same height" << endl;

if (s1 == s2)
{
    cout << "Same Height"<<endl;
}
else
cout<<"Not same"<<endl;

    return 0;
}