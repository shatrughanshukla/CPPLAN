#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Front :" << q.front() << endl; // Access the first element.
    q.pop();
    cout << "the new front : " << q.front() << endl; // Access the front after dequeue.
    return 0;
}