#include<iostream>
using namespace std;

int main()
{
    cout << "For Break" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << i <<endl;
        if (i == 5)
        {
        break;
        }
        
    }
    cout << "for continue"<< endl;
    for (int i = 0; i < 20; i++)
    {
        if (i == 5)
        {
        continue;
        }
        cout << i <<endl; // // this should be places after continue to in order to takeeffect fro continue.
        
    }
    
    return 0;
}