#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(6);
    d.push_front(9);
    d.push_back(2);
    d.push_back(4);

    for (auto it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout<<endl;
    d.pop_front();
     for (auto it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout<<endl;
    d.pop_back();
     for (auto it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    
    return 0;
}