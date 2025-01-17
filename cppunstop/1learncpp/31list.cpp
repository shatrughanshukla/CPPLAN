#include<iostream>
#include<list>
using namespace std;
int main()
{
int n;
cin >> n;
list<int> l;
for (int i = 0; i < n; i++)
{
    int f;
    cin >> f;
    l.push_back(f);
}
l.push_front(5);
for (auto it = l.begin(); it != l.end(); ++it)
{
    cout << *it << " ";
}
    return 0;
}