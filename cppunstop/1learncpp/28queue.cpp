#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    cout << q.front() << endl;
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}