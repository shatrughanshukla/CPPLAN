#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> flist;
    flist.push_front(10);
    flist.push_front(45);
    flist.push_front(56);
    flist.push_front(16);
    forward_list<int>::iterator itr;
    for (/*auto*/ itr = flist.begin(); itr != flist.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;
    flist.pop_front();
    flist.emplace_front(50);
    for (/*auto*/ itr = flist.begin(); itr != flist.end(); ++itr)
    {
        cout << *itr << " ";
    }
    
    return 0;
}